@{%
const moo = require("moo");

const lexer = moo.compile({
	c_word	: /[a-zA-Z0-9_-]+/, // Any type of valid characters combination
	ws		: /[ \t]+/
});
%}

# Pass your lexer object using the @lexer option:
@lexer lexer

words -> (word _):+
# Use %token to match any token of that type instead of "token":
word -> %c_word {% id %}

_ -> %ws:* {% (d) => (null) %}
__ -> %ws:+ {% (d) => (null) %}
