// Generated automatically by nearley, version 2.16.0
// http://github.com/Hardmath123/nearley
(function () {
function id(x) { return x[0]; }


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

var grammar = {
    Lexer: lexer,
    ParserRules: [
    {"name": "PROTOTYPES", "symbols": ["FUNCTION_TYPE_AND_NAME", "PARAMETERS"], "postprocess":  ([func, param]) => {
        	return (Object.assign(func, {parameters: param}))
        } },
    {"name": "PARAMETERS", "symbols": ["RIGHT_PARENTHESE_PARAMETERS", "_", (lexer.has("openAcc") ? {type: "openAcc"} : openAcc)], "postprocess": id},
    {"name": "RIGHT_PARENTHESE_PARAMETERS", "symbols": ["LEFT_PARENTHESE_PARAMETERS", (lexer.has("rightP") ? {type: "rightP"} : rightP)], "postprocess": id},
    {"name": "LEFT_PARENTHESE_PARAMETERS", "symbols": [(lexer.has("leftP") ? {type: "leftP"} : leftP), "_", "PARAMETERS_LIST"], "postprocess": ([leftP, ws, params]) => (params ? params : null)},
    {"name": "PARAMETERS_LIST$ebnf$1", "symbols": ["PARAMETER_AND_COMA"]},
    {"name": "PARAMETERS_LIST$ebnf$1", "symbols": ["PARAMETERS_LIST$ebnf$1", "PARAMETER_AND_COMA"], "postprocess": function arrpush(d) {return d[0].concat([d[1]]);}},
    {"name": "PARAMETERS_LIST", "symbols": ["PARAMETERS_LIST$ebnf$1"], "postprocess": id},
    {"name": "PARAMETER_AND_COMA", "symbols": ["PARAMETER_TYPE_AND_NAME", "COMA", "_"], "postprocess": id},
    {"name": "PARAMETER_TYPE_AND_NAME", "symbols": ["FUNCTION_TYPE_AND_NAME"], "postprocess": id},
    {"name": "FUNCTION_TYPE_AND_NAME", "symbols": ["FUNCTION_RETURN_TYPE", "_", "FUNCTION_NAME", "_"], "postprocess": 
        ([completeReturn, ws, functionName, lws]) => {
        	return (Object.assign(completeReturn, {name: functionName}))
        }
        },
    {"name": "FUNCTION_NAME$ebnf$1", "symbols": [(lexer.has("c_word") ? {type: "c_word"} : c_word)]},
    {"name": "FUNCTION_NAME$ebnf$1", "symbols": ["FUNCTION_NAME$ebnf$1", (lexer.has("c_word") ? {type: "c_word"} : c_word)], "postprocess": function arrpush(d) {return d[0].concat([d[1]]);}},
    {"name": "FUNCTION_NAME", "symbols": ["FUNCTION_NAME$ebnf$1"], "postprocess": (c) => { return (c[0].join(''))}},
    {"name": "FUNCTION_RETURN_TYPE", "symbols": ["RETURN_TYPES", "POINTERS"], "postprocess": 
        ([returnTypes, pointers]) => {
        	return ({returnType: returnTypes, pointers : pointers ? pointers.replaceAll(',', '').trim() : null});
        }
        },
    {"name": "RETURN_TYPES", "symbols": ["RETURN_TYPE"], "postprocess": id},
    {"name": "RETURN_TYPES", "symbols": ["RETURN_TYPE", "__", "RETURN_TYPE"], "postprocess": (c) => c.joinWithoutNull()},
    {"name": "RETURN_TYPES", "symbols": ["RETURN_TYPE", "__", "RETURN_TYPE", "__", "RETURN_TYPE"], "postprocess": (c) => c.joinWithoutNull()},
    {"name": "RETURN_TYPES", "symbols": ["RETURN_TYPE", "__", "RETURN_TYPE", "__", "RETURN_TYPE", "__", "RETURN_TYPE"], "postprocess": (c) => c.joinWithoutNull()},
    {"name": "RETURN_TYPES", "symbols": ["RETURN_TYPE", "__", "RETURN_TYPE", "__", "RETURN_TYPE", "__", "RETURN_TYPE", "__", "RETURN_TYPE"], "postprocess": (c) => c.joinWithoutNull()},
    {"name": "RETURN_TYPES", "symbols": ["RETURN_TYPE", "__", "RETURN_TYPE", "__", "RETURN_TYPE", "__", "RETURN_TYPE", "__", "RETURN_TYPE", "__", "RETURN_TYPE"], "postprocess": (c) => c.joinWithoutNull()},
    {"name": "RETURN_TYPE$ebnf$1", "symbols": [(lexer.has("c_word") ? {type: "c_word"} : c_word)]},
    {"name": "RETURN_TYPE$ebnf$1", "symbols": ["RETURN_TYPE$ebnf$1", (lexer.has("c_word") ? {type: "c_word"} : c_word)], "postprocess": function arrpush(d) {return d[0].concat([d[1]]);}},
    {"name": "RETURN_TYPE", "symbols": ["RETURN_TYPE$ebnf$1"], "postprocess": (c) => (c[0].join(''))},
    {"name": "POINTERS$ebnf$1", "symbols": []},
    {"name": "POINTERS$ebnf$1$subexpression$1", "symbols": ["_", (lexer.has("ptr") ? {type: "ptr"} : ptr)]},
    {"name": "POINTERS$ebnf$1", "symbols": ["POINTERS$ebnf$1", "POINTERS$ebnf$1$subexpression$1"], "postprocess": function arrpush(d) {return d[0].concat([d[1]]);}},
    {"name": "POINTERS", "symbols": ["POINTERS$ebnf$1"], "postprocess": (c) => { return(c[0].join('').trim())}},
    {"name": "COMA$ebnf$1", "symbols": []},
    {"name": "COMA$ebnf$1", "symbols": ["COMA$ebnf$1", (lexer.has("coma") ? {type: "coma"} : coma)], "postprocess": function arrpush(d) {return d[0].concat([d[1]]);}},
    {"name": "COMA", "symbols": ["COMA$ebnf$1"], "postprocess": (d) => (null)},
    {"name": "_$ebnf$1", "symbols": []},
    {"name": "_$ebnf$1", "symbols": ["_$ebnf$1", (lexer.has("ws") ? {type: "ws"} : ws)], "postprocess": function arrpush(d) {return d[0].concat([d[1]]);}},
    {"name": "_", "symbols": ["_$ebnf$1"], "postprocess": (d) => (null)},
    {"name": "__$ebnf$1", "symbols": [(lexer.has("ws") ? {type: "ws"} : ws)]},
    {"name": "__$ebnf$1", "symbols": ["__$ebnf$1", (lexer.has("ws") ? {type: "ws"} : ws)], "postprocess": function arrpush(d) {return d[0].concat([d[1]]);}},
    {"name": "__", "symbols": ["__$ebnf$1"], "postprocess": (d) => (null)}
]
  , ParserStart: "PROTOTYPES"
}
if (typeof module !== 'undefined'&& typeof module.exports !== 'undefined') {
   module.exports = grammar;
} else {
   window.grammar = grammar;
}
})();
