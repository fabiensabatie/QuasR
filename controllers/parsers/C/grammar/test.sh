# Compile and test

nearleyc ptr.ne -o grammar.js
nearley-test grammar.js -q --input "int main(const unsigned long long int var1) {
	int coco = 2;
}

int ft_vec4_transform(t_vec4 *lol) {
	return (lol);
}"
