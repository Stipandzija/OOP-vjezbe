

struct Matrica
{
	int redak;
	int stupac;
	float** m;

	Matrica input(int redak, int stupac);
	Matrica generate(int redak, int stupac, int a, int b);
	Matrica sum(Matrica matrica1, Matrica matrica2, int redak, int stupac);
	Matrica sub(Matrica matrica1, Matrica matrica2, int redak, int stupac);
	Matrica mult(Matrica matrica1, Matrica matrica2, int redak, int stupac);
};
void print(Matrica matrica, int redak, int stupac);