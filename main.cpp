#include <iostream>
#include <vector>
#include <random>
#include <iterator>
#include <algorithm>

std::vector<int> makeMeARandomTab()
{
  // Exemple d'entrée-sortie
  int nb;
  // std::cout : sortie standard (la console), << : opérateur de sortie
  std::cout << "Combien d'éléments voulez-vous ? ";
  // std::cin : entrée standard (le clavier de la console), >> : opérateur d'entrée
  std::cin >> nb;

  std::cout << "Je prépare un tableau de " << nb << " éléments." << std::endl;
  // Création d'un tableau d'entiers intelligent
  // Utilisation du constructeur permettant l'initialisation à une certaine taille
  std::vector<int> tab(nb);

  std::cout << "Le tableau va être rempli par des éléments aléatoires.\n"
            << "Veuillez préciser la borne inférieure des éléments à générer : ";
  int min;
  std::cin >> min;
  std::cout << "Merci.\nEt à présent la borne supérieure : ";
  int max;
  std::cin >> max;

  // Démonstration de swap : échange de deux variables
  if (min > max) {
    std::cout << "Il me semble que vous avez inversé les bornes min et max ; laissez-moi arranger ça pour vous.\n";
    std::swap(min, max);
  }
  std::cout << "Merci, je vais à présent initialiser un générateur pseudo-aléatoire avec une distribution uniforme et remplir le tableau."
            << std::endl;

  // Démonstration de la génération de nombres (pseudo-)aléatoire
  // std::random_device : une source aléatoire (plus ou moins bon
  // en fonction du matériel disponible sur la plate-forme)
  std::random_device r;
  // std::default_random_engine : un générateur pseudo-aléatoire à
  // initialiser avec une graine (la sortie du random_device)
  std::default_random_engine engine(r());
  // std::uniform_int_distribution<int> : un objet capable
  // d'arranger la sortie du générateur pseudo-aléatoire pour fournir
  // des entiers entre des bornes minimale et maximale selon une
  // distribution uniforme
  std::uniform_int_distribution<int> dist(min, max);

  // Exemple de boucle "for each"
  // En recevant n par référence, on peut le modifier
  for (int& n : tab)
    n = dist(engine);

  // Dans la boucle suivante, n est passé par valeur,
  // si on modifie n, on ne modifie que la copie, pas l'élément
  // du tableau d'origine
  // for (int n : tab)

  // Dans la boucle suivante, n est passé par référence constante,
  // on ne peut pas modifier n, cela ne compilera pas
  // Par rapport au passage par copie, on évite une recopie
  // (dans le cas d'un entier, ça ne change pas grand'chose mais
  // pour un objet lourd à instancier, ça gagne du temps et de
  // la mémoire).
  // for (const int& n : tab)

  // Exemple d'utilisation d'un algorithme standard
  std::cout << "Voici votre tableau : ";
  // std::copy : copie les éléments itérés de tab.begin() and tab.end()
  // dans l'itérateur de sortie (troisième argument)
  // std::ostream_iterator<int> : un objet capable d'injecter des int
  // séparés par des espaces (" ") dans la sortie standard (std::cout)
  std::copy(tab.cbegin(), tab.cend(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  return tab;
}

int main() {
  auto tab = makeMeARandomTab();

  std::random_device r;
  std::default_random_engine engine(r());
  std::uniform_int_distribution<int> dist(1, 6);

  // Exemple d'utilisation de switch() (if-else multiple)
  switch (dist(engine)) {
    case 1:
      std::cout << "Chouette tableau, non ?";
      break;
    case 2:
      std::cout << "Hmmm....";
      break;
    case 3:
      std::cout << "Je ne suis pas très satisfait de ce tableau";
      break;
    case 4:
      std::cout << "Oui, oui, c'est... un tableau.";
      break;
    case 5:
      std::cout << "Magnifique !";
      break;
    default:
      std::cout << "Voilà voilà, à la prochaine fois.";
  }
  std::cout << std::endl;
}