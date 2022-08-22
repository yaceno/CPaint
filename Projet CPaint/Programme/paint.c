#include "../lib/libgraphique.h"
#include <stdio.h>
#include <math.h>

void interface();

void ligne(Point pL1, Point pL2, Couleur couleur);

void carrerectanglevide(Point pC, Couleur couleur);

void carrerectangle(Point pC, Couleur couleur);

void cercle(Point pC, Couleur couleur);

void disque(Point pC, Couleur couleur);

void triangle(Point p1, Couleur couleur);

void polygonevide(Point pP1, Point pP2, Couleur couleur);

void inserertexte(Point pC, Couleur couleur);

void effacerplan();

void choixcouleur(Point pC);

void chargementimage(Point pC);

void clean_stdin(void);

Couleur couleur;

Point pI = {225, 725};

int main(void)
	{
	couleur = blanc;
	interface(couleur);
	actualiser();
	while(1)
	{
	Point clic = attendre_clic();
	if ((clic.x < 100) && (clic.x > 50) && (clic.y < 50)) //Condition pour outil ligne
		{
		while(1)
			{
	 		printf("Outil lignes : Cliquez sur deux points\n");
 			Point clictest = attendre_clic();
			if ((clictest.x < 100) || (clictest.y < 25))
				{
				break;
				}
			else if ((clictest.x > 100) && (clictest.y > 25))
				{
        	        	ligne(clictest, attendre_clic(), couleur);
				}
			actualiser();
			}
		}
	else if ((clic.x < 50) && (clic.y < 100) && (clic.y > 50)) //Condition pour outil carré vide
		{
		while(1)
			{
			printf("Outil quadrilatère vide : Cliquez sur le point en haut à gauche\n");
			Point clictest = attendre_clic();
			if ((clictest.x < 100) || (clictest.y < 25))
				{
				break;
				}
			else if ((clictest.x > 100) && (clictest.y > 25))
				{
				carrerectanglevide(clictest, couleur);
				}
			actualiser();
			}
		}
	else if ((clic.x > 50) && (clic.x < 100) && (clic.y < 100) && (clic.y > 50)) //Condition pour outil carré plein
		{
		while(1)
			{
			printf("Outil quadrilatère plein : Cliquez sur le point en haut à gauche\n");
			Point clictest = attendre_clic();
			if ((clictest.x < 100) || (clictest.y < 25))
				{
				break;
				}
			else if ((clictest.x > 100) && (clictest.y > 25))
				{
				carrerectangle(clictest, couleur);
				}
			actualiser();
			}
		}
	else if ((clic.x < 50) && (clic.y >100) && (clic.y < 150)) //Condition pour outil cercle
		{
		while(1)
			{
			printf("Outil cercle : Cliquez sur le centre puis le rayon\n");
			Point clictest = attendre_clic();
			if (clictest.x < 100)
				{
				break;
				}
			else if ((clictest.x > 100) && (clictest.y > 25))
				{
				cercle(clictest, couleur);
				}
			actualiser();
			}
		}
	else if ((clic.x < 100) && (clic.x > 50) && (clic.y >50) && (clic.y < 150) && (clic.y > 100)) //Condition pour outil cercle plein
		{
		while(1)
			{
			printf("Outil cercle plein : Cliquez sur le centre puis le rayon\n");
			Point clictest = attendre_clic();
			if ((clictest.x < 100) || (clictest.y < 25))
				{
				break;
				}
			else if ((clictest.x > 100) && (clictest.y > 25))
				{
				disque(clictest, couleur);
				}
			actualiser();
			}
		}
	else if ((clic.x < 50) && (clic.y < 200) && (clic.y > 150)) //Condtion pour outil triangle
		{
		while(1)
			{
			printf("Outil triangle : Cliquez sur trois points\n");
			Point clictest = attendre_clic();
			if ((clictest.x < 100) || (clictest.y < 25))
				{
				break;
				}
			else if ((clictest.x > 100) && (clictest.y > 25))
				{
				triangle(clictest, couleur);
				}
			actualiser();
			}
		}
	else if ((clic.y < 250) && (clic.y > 200) && (clic.x < 50)) //Condition pour outil polygone vide
		{
		while(1)
			{
			printf("Outil polygone vide : cliquez avec clic gauche pour créer de nouveaux points, clic droit pour fermer le polygone\n");
			Point clictest1 = attendre_clic();
			Point clictest2 = attendre_clic();
			if ((clictest1.x < 100) || (clictest2.x < 100) || (clictest1.y < 25) || (clictest2.y < 25))
				{
				break;
				}
			else if ((clictest1.x > 100) && (clictest1.y > 25) && (clictest2.x > 100) && (clictest2.y > 25))
				{
				polygonevide(clictest1, clictest2, couleur);
				}
			actualiser();
			}
		}
	else if ((clic.x < 50) && (clic.y < 300) && (clic.y > 250)) //Condition pour outil texte
		{
		while(1)
			{
			printf("Outil texte : Cliquez sur le point de début du texte\n");
			Point clictest = attendre_clic();
			if ((clictest.x < 100) || (clictest.y < 25))
				{
				break;
				}
			else if ((clictest.x > 100) && (clictest.y > 25))
				{
				inserertexte(clictest, couleur);
				}
			actualiser();
			}
		}
	else if ((clic.x < 50) && (clic.y > 300) && (clic.y < 350)) //Condition pour outil effacer écran
		{
		effacerplan();
		}
	else if ((clic.x < 100) && (clic.y > 750))
		{
		choixcouleur(clic);
		}
	else if ((clic.x < 1375) && (clic.x > 1350) && (clic.y < 25)) //Condition pour outil chargement image
		{
		printf("Outil chargement d'image : Cliquez sur le point où l'image va être ouverte\n");
		Point clictest = attendre_clic();
		if ((clictest.x < 100) || (clictest.y < 25))
			{
			break;
			}
		else if ((clictest.x > 100) && (clictest.y > 25))
			{
			chargementimage(clictest);
			}
		}
	else if ((clic.x > 1375) && (clic.y < 25)) //Condition pour fermer la fenêtre
		{
		printf("Merci d'avoir utilisé notre programme !\nCréé par Yacine SOUAM et Merwane ZIOUI, élèves de 1ère année.\n");
		fermer_fenetre();
		}
	actualiser();
	}
	return 0;
	}

void interface(Couleur couleur)
	{
	Point pI = {0, 0};
	ouvrir_fenetre(1400,800);
	afficher_image("InterfacePaint.bmp", pI);
	Point pCOR = {0,750}; //Rouge
	Point pCOV = {25, 750}; //Vert
	Point pCOB = {50, 750}; //Bleu
	Point pCOBl = {75, 750}; //couleur
	Point pCOA = {0, 775}; //Argent
	Point pCOMa = {25, 775}; //Magenta
	Point pCOCy = {50, 775}; //Cyan
	Point pCOJ = {75, 775}; //Jaune
	dessiner_rectangle(pCOR, 25, 25, rouge);
	dessiner_rectangle(pCOV, 25, 25, vert);
	dessiner_rectangle(pCOB, 25, 25, bleu);
	dessiner_rectangle(pCOBl, 25, 25, blanc);
	dessiner_rectangle(pCOA, 25, 25, argent);
	dessiner_rectangle(pCOMa, 25, 25, magenta);
	dessiner_rectangle(pCOCy, 25, 25, cyan);
	dessiner_rectangle(pCOJ, 25, 25, jaune);
	Point pCC = {25, 705};
	dessiner_rectangle(pCC, 50, 25, couleur);
	}

void ligne(Point pL1, Point pL2, Couleur couleur)
	{
	int i, initx1, initx2, inity1, inity2;
	int e = 1;
	int epaisseur;
	dessiner_ligne(pL1, pL2, couleur);
	inity1 = pL1.y;
	inity2 = pL2.y;
	initx1 = pL1.x;
	initx2 = pL2.x;
	printf("Choisissez une épaisseur: \n"); //choix de l'épaisseur
	scanf("%d",&epaisseur);
	for (i=0; i<epaisseur; i++)
		{
		if ((pL1.y) == (pL2.y))
			{
			pL1.y = inity1; //initialisation des  points (on les remet à leurs positions initiales)
			pL2.y = inity2;//
			pL1.y += e;
			pL2.y += e;
			dessiner_ligne(pL1, pL2, couleur);
			e++;
			pL1.y -= e;
			pL2.y -= e;
			dessiner_ligne(pL1, pL2, couleur);
			}
		else
			{
			pL1.x = initx1; //initialisation des points (on les remet à leurs positions initiales)
			pL2.x = initx2;//
			pL1.x += e;
			pL2.x += e;
			dessiner_ligne(pL1, pL2, couleur);
			e++;
			pL1.x -= e;
			pL2.x -= e;
			dessiner_ligne(pL1, pL2, couleur);
			}
		}
	}

void carrerectanglevide(Point pC, Couleur couleur)
	{
	Point pCC = {25, 705};
	int largeur, hauteur;
	Point pG = {0, 0};
	Point pH = {100, 0};
	Point p1, p2, p3;
	printf("Choisissez la largeur et la hauteur :\n");
	scanf("%d", &largeur);
	scanf("%d", &hauteur);
	p1.x = pC.x + largeur; //Ici, on détermine l'emplacement des 3 points restants
	p1.y = pC.y;
	p2.x = pC.x + largeur;
	p2.y = pC.y + hauteur;
	p3.x = pC.x;
	p3.y = pC.y + hauteur;
	dessiner_ligne(pC, p1, couleur);
	dessiner_ligne(p1, p2, couleur);
	dessiner_ligne(p2, p3, couleur);
	dessiner_ligne(p3, pC, couleur);
	afficher_image("BarreHaut.bmp", pH);
	afficher_image("BarreOutils.bmp", pG);
	dessiner_rectangle(pCC, 50, 25, couleur);
	clean_stdin();
	}

void carrerectangle(Point pC, Couleur couleur)
	{
	Point pCC = {25, 705};
	int largeur, hauteur;
	Point pG = {0, 0};
	Point pH = {100, 0};
	printf("Choisissez la largeur et la hauteur :\n");
	scanf("%d", &largeur);
	scanf("%d", &hauteur);
	dessiner_rectangle(pC, largeur, hauteur, couleur);
	afficher_image("BarreHaut.bmp", pH);
	afficher_image("BarreOutils.bmp", pG);
	dessiner_rectangle(pCC, 50, 25, couleur);
	clean_stdin();
	}

void cercle(Point pC, Couleur couleur)
	{
	Point pCC = {25, 705};
	int rayon;
	Point pG = {0, 0};
	Point pH = {100, 0};
	Point pR = attendre_clic();
	rayon = sqrt(pow(pR.x - pC.x, 2) + pow(pR.y - pC.y, 2)); //Calcul du rayon
	dessiner_cercle(pC, rayon, couleur);
	afficher_image("BarreHaut.bmp", pH); //On raffiche l'interface pour éviter que le cercle dépasse sur les icones
	afficher_image("BarreOutils.bmp", pG);
	dessiner_rectangle(pCC, 50, 25, couleur);
	}

void disque(Point pC, Couleur couleur)
	{
	Point pCC = {25, 705};
	int rayon;
	Point pG = {0, 0};
	Point pH = {100, 0};
	Point pR = attendre_clic();
	rayon = sqrt(pow(pR.x - pC.x, 2) + pow(pR.y - pC.y, 2)); //Calcul du rayon
	dessiner_disque(pC, rayon, couleur);
	afficher_image("BarreHaut.bmp", pH); //On raffiche l'interface pour éviter que le cercle dépasse sur les icones
	afficher_image("BarreOutils.bmp", pG);
	dessiner_rectangle(pCC, 50, 25, couleur);
	}

void triangle(Point p1, Couleur couleur)
	{
	Point p2 = attendre_clic();
	Point p3 = attendre_clic();
	dessiner_ligne(p1, p2, couleur);
	dessiner_ligne(p2, p3, couleur);
	dessiner_ligne(p1, p3, couleur);
	}

void polygonevide(Point pP1, Point pP2, Couleur couleur)
	{
	Point pPb;
	Point pPa = {pP2.x, pP2.y};
	dessiner_ligne(pP1, pP2, couleur);
	while(1)
		{
		pPb = attendre_clic_gauche_droite(); //On cherche à savoir si l'utilisateur souhaite créer un point ou fermer son polygone
		if (pPb.x<0)
			{
			if ((-pPb.x > 100)&& (-pPb.y > 25)) //Condition de fermeture du polygone lorsque le clic droit est détecté
				{
				Point pPbnv = {-pPb.x, -pPb.y};
				dessiner_ligne(pPa, pPbnv, couleur);
				dessiner_ligne(pPbnv, pP1, couleur);
				break;
				}
			}
		else if (pPb.x>0)
			{
			if ((pPb.x > 100)&& (pPb.y > 25))
				{
				dessiner_ligne(pPa, pPb, couleur);
				pPa = pPb;
				actualiser();
				}
			}
		}
	}

void inserertexte(Point pC, Couleur couleur)
	{
	int taille;
	char texte[50];
	printf("Saisir texte :\n");
	scanf("%[^\n]s", texte);
	printf("Choisir taille texte\n");
	scanf("%d", &taille);
	afficher_texte(texte, taille, pC, couleur);
	actualiser();
	clean_stdin();
	}

void effacerplan()
	{
	Point pCC = {25, 705};
	Point pE = {100, 25};
	dessiner_rectangle(pE, 1300, 775, noir);
	Point pG = {0, 0};
	Point pH = {100, 0};
	afficher_image("BarreHaut.bmp", pH);
	afficher_image("BarreOutils.bmp", pG);
	dessiner_rectangle(pCC, 50, 25, couleur);
	printf("Zone de dessin effacée.\n");
	}

void choixcouleur(Point pC)
	{
	Point pCC = {25, 705};
	if((pC.x < 25) && (pC.y > 750) && (pC.y < 775))
		{
		couleur = rouge;
		dessiner_rectangle(pCC, 50, 25, couleur);
		printf("Couleur : rouge\n");
		}
	else if((pC.x < 50) && (pC.x > 25) && (pC.y > 750) && (pC.y < 775))
		{
		couleur = vert;
		dessiner_rectangle(pCC, 50, 25, couleur);
		printf("Couleur : vert\n");
		}
	else if((pC.x < 75) && (pC.x > 50) && (pC.y > 750) && (pC.y < 775))
		{
		couleur = bleu;
		dessiner_rectangle(pCC, 50, 25, couleur);
		printf("Couleur : bleu\n");
		}
	else if((pC.x < 100) && (pC.x > 75) && (pC.y > 750) && (pC.y < 775))
		{
		couleur = blanc;
		dessiner_rectangle(pCC, 50, 25, couleur);
		printf("Couleur : blanc\n");
		}
	else if((pC.x < 25) && (pC.y > 775) && (pC.y < 800))
		{
		couleur = argent;
		dessiner_rectangle(pCC, 50, 25, couleur);
		printf("Couleur : argent\n");
		}
	else if((pC.x < 50) && (pC.x > 25) && (pC.y > 775))
		{
		couleur = magenta;
		dessiner_rectangle(pCC, 50, 25, couleur);
		printf("Couleur : magenta\n");
		}
	else if((pC.x < 75) && (pC.x > 50) && (pC.y > 775))
		{
		couleur = cyan;
		dessiner_rectangle(pCC, 50, 25, couleur);
		printf("Couleur : cyan\n");
		}
	else if((pC.x < 100) && (pC.x > 75) && (pC.y > 775))
		{
		couleur = jaune;
		dessiner_rectangle(pCC, 50, 25, couleur);
		printf("Couleur : jaune\n");
		}
	}

void chargementimage(Point pC)
	{
	char nom[60];
	printf("Saisissez le nom du fichier à charger ou son chemin (format .bmp et max 60 caractères) :\n");
	scanf("%[^\n]s", nom);
	afficher_image(nom, pC);
	clean_stdin();
	}


void clean_stdin(void) //https://stackoverflow.com/questions/17318886/fflush-is-not-working-in-linux
	{
	int c;
	do
		{
		c = getchar();
		}
	while (c != '\n' && c != EOF);
	}
