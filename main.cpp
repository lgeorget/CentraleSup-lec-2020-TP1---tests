#include <iostream>
#include <vector>
#include <random>
#include <iterator>
#include <algorithm>

std::vector<int> makeMeARandomTab()
{
  int nb;
  std::cout << "Combien d'éléments voulez-vous ? ";
  std::cin >> nb;

  std::cout << "Je prépare un tableau de " << nb << " éléments." << std::endl;
  std::vector<int> tab(nb);

  std::cout << "Le tableau va être rempli par des éléments aléatoires.\n"
            << "Veuillez préciser la borne inférieure des éléments à générer : ";
  int min;
  std::cin >> min;
  std::cout << "Merci.\nEt à présent la borne supérieure : ";
  int max;
  std::cin >> max;

  if (min > max) {
    std::cout << "Il me semble que vous avez inversé les bornes min et max ; laissez-moi arranger ça pour vous.\n";
    std::swap(min, max);
  }
  std::cout << "Merci, je vais à présent initialiser un générateur pseudo-aléatoire avec une distribution uniforme et remplir le tableau."
            << std::endl;

  std::random_device r;
  std::default_random_engine engine(r());
  std::uniform_int_distribution<int> dist(min, max);

  for (int& n : tab)
    n = dist(engine);

  std::cout << "Voici votre tableau : ";
  std::copy(tab.cbegin(), tab.cend(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  return tab;
}

int main() {
  auto tab = makeMeARandomTab();

  std::random_device r;
  std::default_random_engine engine(r());
  std::uniform_int_distribution<int> dist(1, 6);
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