#include <stdio.h>
#include <stdlib.h>




int main(int argc, const char *argv[])
{
	char *filename = "data/x.bin";
	char *mode = "rb";
	FILE *f = NULL;
	double z = 0.;
	int num_elements = 1;

	f = fopen(filename, mode);
	if (NULL == f)
	{
		printf("Error, unable to open file %s\n", filename);
		return 1;
	}

	if (num_elements != fread(&z, sizeof(double), num_elements, f))
	{
		printf("Error, unable to read %d elements to file %s\n", num_elements, filename);
		return 1;
	}
	if (0 != fclose(f))
	{
		printf("Error, unable to close file %s\n", filename);
		return 1;
	}
	printf("z=%lf\n", z);
	return 0;
}

// pour la prochaine fois lundi 11 mars 2024 :
// - reprendre le TD20240227
// - transformer la création du fichier texte en fichier binaire
// - relire le contenu du fichier, et afficher les deux valeurs moyennes
// - comparez les valeurs moyennes avec les valeurs moyennes calculées lors de l'écriture du fichier