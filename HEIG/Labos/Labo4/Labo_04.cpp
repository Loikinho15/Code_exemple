//
// Created by loicd on 30.09.2024.
//
#include <iostream>
#include <random>
using namespace std;
/*
int main () {
//----------------------------------------------- QUESTIONS A L'UTILISATEUR ---------------------------------------------------------------------------
  char mode;
  do {
    cout << "Mode jeu ou mode test ? Répondre par \'j\' ou \'t\'";
    cin >> mode;
  } while (mode != 'j' && mode != 't');

  char is_rand;
  do {
    cout << "Voulez-vous utiliser la méthode aléatoire ? Répondre par \'o\' pour oui ou \'n\' pour non.";
    cin >> is_rand;
  } while (is_rand != 'o' && is_rand != 'n');

  //Définition de la borne inférieur de l'intervalle qui DOIT être un nombre positif
  int min_intervalle = 0;
  do {
    cout << "Entrez l'intervalle inférieure : ";
    cin >> min_intervalle;
  } while (min_intervalle < 0);

  //Définition de la borne supérieur de l'intervalle qui DOIT être suppérieur à la borne inférieur
  int max_intervalle = 0;
  do {
    cout << "Entrez l'intervalle supérieure : ";
    cin >> max_intervalle;
  } while (max_intervalle < 0 && max_intervalle > min_intervalle);

  //Si les intervalles sont dans le mauvaises ordres
  //on les remets dans le bon ordre en utilisant l'addition et la soustraction de la somme
  if (max_intervalle < min_intervalle) {
    min_intervalle = min_intervalle + max_intervalle;
    max_intervalle = min_intervalle - max_intervalle;
    min_intervalle = min_intervalle - max_intervalle;
  }
//------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------- INITIALISATION DES VARIABLES COMMUNES -----------------------------------------------------
  int x = 0; //L'intervalle
  bool nb_found = false; // par défaut le nombre n'est pas trouvé
  int count = 1; //nombre d'itération pour trouver le nombre recherché
  char answer; //réponse à la question
  int nb_to_guess = 0; //le nombre à trouver POUR LE MODE TEST
//------------------------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------- MODE NORMAL ------------------------------------------------------------------
  if (is_rand == 'n') {
    if (mode == 'j') {
      cout << "Choisissez un nombre dans cette intervalle, puis répondez au questions par \'o\' pour oui et \'n\' pour non." << endl;
    } else {
      do {
        cout << "Entrez le nombre que vous avez choisi : ";
        cin >> nb_to_guess;
      } while (nb_to_guess < min_intervalle || nb_to_guess > max_intervalle);
    }
    do {
      //L'intervalle est le milieu des bornes supp et inf
      x = (max_intervalle - min_intervalle) / 2 + min_intervalle;
      cout << count++ << ". Le nombre est-il plus petit ou egal a " << x << " ?";
      if (mode == 'j') {
        cin >> answer;
      } else {
        if (nb_to_guess > x) {
          answer = 'n';
          cout << " " << answer << endl;
        } else {
          answer = 'o';
          cout << " " << answer << endl;
        }
      }
      if (answer == 'n') { //nombre > que x
        // L'intervalle min sera de toute façon plus grand que l'intervalle du millieu car il est compris (plus petit ou égal à) donc on ajout 1
        min_intervalle = x + 1;
        if (max_intervalle == min_intervalle) { // ici on ne peut plus recalculer l'intervalle donc on est sur le nombre recherché
          cout << "Le nombre choisi est " << max_intervalle << endl;
          nb_found = true;
        }
      }
      else {
        // L'intervalle max devient l'intervalle du millieu car il est compris (plus petit ou égal à) donc on ajout 1
        max_intervalle = x;
        if (min_intervalle == max_intervalle) { // ici on ne peut plus recalculer l'intervalle donc on est sur le nombre recherché
          cout << "Le nombre choisi est " << max_intervalle << endl;
          nb_found = true;
        }
      }
    } while(nb_found == false);
  }
//------------------------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------- MODE RANDOM ------------------------------------------------------------------
  else {
    random_device seed;
    mt19937 generator(seed());
    if (mode == 'j') {
      cout << "Choisissez un nombre dans cette intervalle, puis répondez au questions par \'o\' pour oui et \'n\' pour non." << endl;
    } else {
      do {
        cout << "Entrez le nombre que vous avez choisi : ";
        cin >> nb_to_guess;
      } while (nb_to_guess < min_intervalle || nb_to_guess > max_intervalle);
    }
    do {
      //L'intervalle des bornes est aléatoire et entre les bornes incluses
      uniform_int_distribution<> distrib(min_intervalle, max_intervalle);
      x = distrib(generator);
      cout << count++ << ". Le nombre est-il plus petit ou egal a " << x << " ?";

      if (mode == 'j') {
        cin >> answer;
      } else {
        if (nb_to_guess > x) {
          answer = 'n';
          cout << " " << answer << endl;
        } else {
          answer = 'o';
          cout << " " << answer << endl;
        }
      }
      if (answer == 'n') {
        // L'intervalle min sera de toute façon plus grand que l'intervalle du millieu car il est compris (plus petit ou égal à) donc on ajout 1
        min_intervalle = x + 1;
        if (max_intervalle == min_intervalle) { // ici on ne peut plus recalculer l'intervalle donc on est sur le nombre recherché
          cout << "Le nombre choisi est " << max_intervalle << endl;
          nb_found = true;
        }
      }
      else {
        // L'intervalle max devient l'intervalle du millieu car il est compris (plus petit ou égal à) donc on ajout 1
        max_intervalle = x;
        if (min_intervalle == max_intervalle) { // ici on ne peut plus recalculer l'intervalle donc on est sur le nombre recherché
          cout << "Le nombre choisi est " << max_intervalle << endl;
          nb_found = true;
        }
      }
    } while(nb_found == false);
  }
//------------------------------------------------------------------------------------------------------------------------------------------------
  return EXIT_SUCCESS;
}*/