@{%

const moo = require("moo");

const lexer = moo.compile({
	c_word			: /[a-zA-Z0-9_-]+/, // Any type of valid characters combination
	ws				: { match: /[ \n\t\r\v\s]+/, lineBreaks: true },
	ptr				: { match: /[*]+/ },
	leftP			: { match: /[(]+/ },
	coma			: { match: /[,]+/ },
	rightP			: { match: /[)]+/ },
	openAcc			: { match: /[{]+/ }
});

String.prototype.replaceAll = function(search, replacement) {
	return this.replace(new RegExp(search, 'g'), replacement);
};

Array.prototype.joinWithoutNull = function() {
	let joinedString = "";
	for (let item of this) if (item) joinedString += ` ${item}`;
	return (joinedString.trim());
}

%}

@lexer lexer

# Prototypes
PROTOTYPES -> FUNCTION_TYPE_AND_NAME PARAMETERS {% ([func, param]) => {
	return (Object.assign(func, {parameters: param}))
} %}

# Parameters related rules

PARAMETERS -> RIGHT_PARENTHESE_PARAMETERS _ %openAcc {% id %}

RIGHT_PARENTHESE_PARAMETERS -> LEFT_PARENTHESE_PARAMETERS %rightP {% id %}
LEFT_PARENTHESE_PARAMETERS -> %leftP _ PARAMETERS_LIST {% ([leftP, ws, params]) => (params ? params : null) %}

PARAMETERS_LIST -> PARAMETER_AND_COMA:+ {% id %}

PARAMETER_AND_COMA -> PARAMETER_TYPE_AND_NAME COMA _ {% id %}

PARAMETER_TYPE_AND_NAME -> FUNCTION_TYPE_AND_NAME {% id %}

# Function related rules
FUNCTION_TYPE_AND_NAME -> FUNCTION_RETURN_TYPE _ FUNCTION_NAME _ {%
	([completeReturn, ws, functionName, lws]) => {
		return (Object.assign(completeReturn, {name: functionName}))
	}
%}

FUNCTION_NAME -> %c_word:+ {% (c) => { return (c[0].join(''))} %}

FUNCTION_RETURN_TYPE -> RETURN_TYPES POINTERS {%
	([returnTypes, pointers]) => {
		return ({returnType: returnTypes, pointers : pointers ? pointers.replaceAll(',', '').trim() : null});
	}
%}

# Function and prototypes related rules
RETURN_TYPES ->	  RETURN_TYPE {% id %}
				| RETURN_TYPE __ RETURN_TYPE {% (c) => c.joinWithoutNull() %}
				| RETURN_TYPE __ RETURN_TYPE __ RETURN_TYPE {% (c) => c.joinWithoutNull() %}
				| RETURN_TYPE __ RETURN_TYPE __ RETURN_TYPE __ RETURN_TYPE {% (c) => c.joinWithoutNull() %}
				| RETURN_TYPE __ RETURN_TYPE __ RETURN_TYPE __ RETURN_TYPE __ RETURN_TYPE {% (c) => c.joinWithoutNull() %}
				| RETURN_TYPE __ RETURN_TYPE __ RETURN_TYPE __ RETURN_TYPE __ RETURN_TYPE __ RETURN_TYPE {% (c) => c.joinWithoutNull() %}

RETURN_TYPE -> %c_word:+ {% (c) => (c[0].join('')) %}
POINTERS -> (_ %ptr):* {% (c) => { return(c[0].join('').trim())} %}

COMA -> %coma:* {% (d) => (null) %}
_ -> %ws:* {% (d) => (null) %}
__ -> %ws:+ {% (d) => (null) %}
