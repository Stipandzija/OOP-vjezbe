

struct Matrica
{
	int redak;
	int stupac;
	float** m;

	static Matrica input(int redak, int stupac);
	static Matrica generate(int redak, int stupac, int a, int b);
	static Matrica sum(Matrica matrica1, Matrica matrica2, int redak, int stupac);
	static Matrica sub(Matrica matrica1, Matrica matrica2, int redak, int stupac);
	static Matrica mult(Matrica matrica1, Matrica matrica2, int redak, int stupac);
};
void print(Matrica matrica, int redak, int stupac);