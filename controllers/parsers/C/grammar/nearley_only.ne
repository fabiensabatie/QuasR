

# Prototypes
#PROTOTYPE -> FUNCTION_TYPE_AND_NAME _ "(" _ ")" _ ";"

PARAMETER_TYPE_AND_NAME -> PARAMETER_TYPE PARAMETER_NAME {%
	([completeReturn, functionName]) => {
		console.clear();
		console.log(completeReturn, functionName);
		return (Object.assign(completeReturn, {name: functionName}))
	}
%}

FUNCTION_TYPE_AND_NAME -> FUNCTION_RETURN_TYPE FUNCTION_NAME {%
	([completeReturn, functionName]) => {
		console.clear();
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
FUNCTION_NAME -> [a-zA-Z0-9_-]:+ {% (c) => (c[0].join('')) %}
FUNCTION_RETURN_TYPE -> RETURN_TYPES POINTERS {%
	([returnTypes, pointers]) => {
		return ({functionReturnType: returnTypes, pointers : pointers ? pointers.replaceAll(' ', '').trim() : null});
	}
%}

# Function and prototypes related rules
RETURN_TYPES ->	  RETURN_TYPE {% id %}
				| RETURN_TYPE __ RETURN_TYPE {% (c) => c.joinWithoutNull() %}
				| RETURN_TYPE __ RETURN_TYPE __ RETURN_TYPE {% (c) => c.joinWithoutNull() %}

RETURN_TYPE -> [+a-zA-Z0-9_-]:+ {% (c) => (c[0].join('')) %}
POINTERS -> [ \t\n\v\f*]:* {% (c) => (c[0].join('').trim()) %}

_  -> space:* {% (d) => (null) %}
__ -> space:+ {% (d) => (null) %}

space -> [ \t\n\v\f] {% id %}
