// Generated automatically by nearley, version 2.16.0
// http://github.com/Hardmath123/nearley
(function () {
function id(x) { return x[0]; }


const moo = require("moo");

const lexer = moo.compile({
	c_word:	/[a-zA-Z0-9_-]+/, // Any type of valid characters combination
	pointers : /[ \t\n\v\f\*]*/ // Pointer characters (includes whitespaces)
});

String.prototype.replaceAll = function(search, replacement) {
	return this.replace(new RegExp(search, 'g'), replacement);
};

Array.prototype.joinWithoutNull = function() {
	let joinedString = "";
	for (let item of this) if (item) joinedString += ` ${item}`;
	return (joinedString.trim());
}

var grammar = {
    Lexer: undefined,
    ParserRules: [
    {"name": "PARAMETER_TYPE_AND_NAME", "symbols": ["PARAMETER_TYPE", "PARAMETER_NAME"], "postprocess": 
        ([completeReturn, functionName]) => {
        	console.clear();
        	console.log(completeReturn, functionName);
        	return (Object.assign(completeReturn, {name: functionName}))
        }
        },
    {"name": "FUNCTION_TYPE_AND_NAME", "symbols": ["FUNCTION_RETURN_TYPE", "FUNCTION_NAME"], "postprocess": 
        ([completeReturn, functionName]) => {
        	console.clear();
        	return (Object.assign(completeReturn, {name: functionName}))
        }
        },
    {"name": "PARAMETER_NAME", "symbols": ["FUNCTION_NAME"], "postprocess": id},
    {"name": "PARAMETER_TYPE", "symbols": ["RETURN_TYPES", "POINTERS"], "postprocess": 
        ([returnTypes, pointers]) => {
        	return ({parameterReturnType: returnTypes, pointers : pointers ? pointers.replaceAll(' ', '').trim() : null});
        }
        },
    {"name": "FUNCTION_NAME", "symbols": [c_word], "postprocess": id},
    {"name": "FUNCTION_RETURN_TYPE", "symbols": ["RETURN_TYPES", "POINTERS"], "postprocess": 
        ([returnTypes, pointers]) => {
        	return ({functionReturnType: returnTypes, pointers : pointers ? pointers.replaceAll(' ', '').trim() : null});
        }
        },
    {"name": "RETURN_TYPES", "symbols": ["RETURN_TYPE"], "postprocess": id},
    {"name": "RETURN_TYPES", "symbols": ["RETURN_TYPE", "__", "RETURN_TYPE"], "postprocess": (c) => c.joinWithoutNull()},
    {"name": "RETURN_TYPES", "symbols": ["RETURN_TYPE", "__", "RETURN_TYPE", "__", "RETURN_TYPE"], "postprocess": (c) => c.joinWithoutNull()},
    {"name": "RETURN_TYPE", "symbols": [c_word], "postprocess": id},
    {"name": "POINTERS", "symbols": [pointers], "postprocess": (c) => (c[0].join('').trim())},
    {"name": "_$ebnf$1", "symbols": []},
    {"name": "_$ebnf$1", "symbols": ["_$ebnf$1", "space"], "postprocess": function arrpush(d) {return d[0].concat([d[1]]);}},
    {"name": "_", "symbols": ["_$ebnf$1"], "postprocess": (d) => (null)},
    {"name": "__$ebnf$1", "symbols": ["space"]},
    {"name": "__$ebnf$1", "symbols": ["__$ebnf$1", "space"], "postprocess": function arrpush(d) {return d[0].concat([d[1]]);}},
    {"name": "__", "symbols": ["__$ebnf$1"], "postprocess": (d) => (null)},
    {"name": "space", "symbols": [/[ \t\n\v\f]/], "postprocess": id}
]
  , ParserStart: "PARAMETER_TYPE_AND_NAME"
}
if (typeof module !== 'undefined'&& typeof module.exports !== 'undefined') {
   module.exports = grammar;
} else {
   window.grammar = grammar;
}
})();
