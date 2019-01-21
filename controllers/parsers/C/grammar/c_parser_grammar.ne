@{%

const moo = require("moo");

const lexer = moo.compile({
	c_word			: /[a-zA-Z0-9_-]+/, // Any type of valid characters combination
	ws				: { match: /[ \n\t\r\v\s]+/, lineBreaks: true },
	ptr				: { match: /\*+/ }
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
PROTOTYPE -> FUNCTION_TYPE_AND_NAME
#
# PARAMETER_TYPE_AND_NAME -> PARAMETER_TYPE PARAMETER_NAME {%
# 	([completeReturn, functionName]) => {
# 		console.clear();
# 		console.log(completeReturn, functionName);
# 		return (Object.assign(completeReturn, {name: functionName}))
# 	}
# %}

FUNCTION_TYPE_AND_NAME -> FUNCTION_RETURN_TYPE FUNCTION_NAME {%
	([completeReturn, functionName]) => {
		return (Object.assign(completeReturn, {name: functionName}))
	}
%}

# Parameters related rules
PARAMETER_NAME -> FUNCTION_NAME {% id %}
PARAMETER_TYPE -> RETURN_TYPES POINTERS {%
	([returnTypes, pointers]) => {
		return ({parameterReturnType: returnTypes, pointers : pointers ? pointers.replaceAll(' ', '').trim() : null});
	}
%}

# Function related rules
FUNCTION_NAME -> %c_word:+ {% (c) => { console.log('c -----\n', c); return (c[0].join(''))} %}
FUNCTION_RETURN_TYPE -> RETURN_TYPES POINTERS {%
	([returnTypes, pointers]) => {
		return ({functionReturnType: returnTypes, pointers : pointers ? pointers.replaceAll(' ', '').trim() : null});
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
POINTERS -> (_ %ptr):* {% (c) => { console.clear(); console.log(c[0]); return(c[0].join('').trim())} %}

_ -> %ws:* {% (d) => (null) %}
__ -> %ws:+ {% (d) => (null) %}
