/* ---------------------------
Laboratoire : 05
Auteur(s) : Timoteo Piaget, Loic Damon
Dernière modification : 06.11.2024
But : montantEnToutesLettres
Remarque(s) :
--------------------------- */

#include <iomanip>
#include <iostream>
#include <cmath>


using namespace std;

/**
 *  Retourne le nom de l'unité en toutes lettres.
 *  @unite Unité du nombre
 *  @i Position actuelle dans la valeur (milliers, millions, etc.)
 *  @dizaine Valeur de la dizaine
 *  @centaine Valeur de la centaine
 *  @return La représentation en toutes lettres de l'unité
 **/
string switchUniteCaractere(unsigned int unite,long long int i, unsigned int dizaine, unsigned int centaine) {

    string str;
    switch(unite) {
        case 0: break;
        case 1:
            if (i > 1000) { //gère les cas des millions/milliards/billions (ex: un million)
                str += "un ";
            } else if (i < 1000) { //Permet de ne pas tomber dans le cas spécial pour mille et ne rien afficher
                if (dizaine != 0) { //Ajout de la liaison 'et-un" après les dizaines (ex: "vingt-et-un")
                    str += "et-un";
                } else {
                    str += "un"; //Ajoute 'un' pour les montants de 1 jusqu'à 999.99 (ex: "neuf-cent-un francs")
                }
            }
        break;
        case 2: str += "deux"; break;
        case 3: str += "trois"; break;
        case 4: str += "quatre"; break;
        case 5: str += "cinq"; break;
        case 6: str += "six"; break;
        case 7: str += "sept"; break;
        case 8: str += "huit"; break;
        case 9: str += "neuf"; break;
        default:
            // option par défaut (peut rester vide si rien à faire)
            break;
    }
    //si on traite des milliers/millions/milliards/billions il faut ajouter un '-' sauf pour le cas de mille
    if (i >= 1000 && unite != 1) {
        str += '-';
    }
    return str;
}

/**
 * Retourne le nom de la dizaine en toutes lettres.
 *  @dizaine Valeur de la dizaine
 *  @unite Valeur de l'unité pour gérer les cas de 10 à 19
 *  @return La représentation en toutes lettres de la dizaine
 **/
string switchDizaineCaractere (unsigned int dizaine,unsigned int unite) {
    string str;
    switch (dizaine) {
        case 1:
            switch (unite) {
                case 0: str += "dix"; break;
                case 1: str += "onze"; break;
                case 2: str += "douze"; break;
                case 3: str += "treize"; break;
                case 4: str += "quatorze"; break;
                case 5: str += "quinze"; break;
                case 6: str += "seize"; break;
                case 7: str += "dix-sept"; break;
                case 8: str += "dix-huit"; break;
                case 9: str += "dix-neuf"; break;
                default:
                    // option par défaut (peut rester vide si rien à faire)
                    break;
            }
            break;
        case 2: str += "vingt"; break;
        case 3: str += "trente"; break;
        case 4: str += "quarante"; break;
        case 5: str += "cinquante"; break;
        case 6: str += "soixante"; break;
        case 7: str += "septante"; break;
        case 8: str += "huitante"; break;
        case 9: str += "nonante"; break;
        default:
            // option par défaut (peut rester vide si rien à faire)
            break;
    }
    //Ajoute un '-' après la dizaine à partir de 20 jusqu'à 99 (ex: "vingt-deux")
    if (dizaine > 1 && unite != 0) {
        str += '-';
    }
    return str;
}

/**
 * Convertit une centaine en toutes lettres.
 * @param centaine Valeur de la centaine
 * @param dizaine Valeur de la dizaine
 * @param unite Valeur de l'unité
 * @param i Position actuelle (milliers, millions, etc.)
 * @return La représentation en toutes lettres de la centaine
 **/
string centaineEnLettres(unsigned int centaine, unsigned int dizaine, unsigned int unite, long long int i) {
    if (centaine == 0) return ""; // Pas de centaine

    string str = (centaine == 1) ? "cent" : switchUniteCaractere(centaine, 0, 0, 0) + "-cent";

    // Ajoute un "s" à la fin uniquement si la centaine est pleine sauf pour cent (ex: "deux-cents")
    if (i != 1000 && centaine != 1 && dizaine == 0 && unite == 0) {
        str += "s";
    }
    //Traite les centaines de millions / milliards / billions (ex: deux-cents-millions)
    if (dizaine != 0 || unite != 0) {
        str += '-';
    }
    return str;
}

/**
 * Associe les suffixes pour chaque tranche de valeurs (mille, million, milliard, billion).
 * @param reste Valeur de la tranche actuelle
 * @param i Position de la tranche
 * @return Le suffixe approprié en fonction de la tranche
 **/
string switchSuffixe(long long int reste, long long int i) {
    string str;
    switch (i) {
        case 1000000000000: str += (reste > 1) ? "billions" : "billion"; break;
        case 1000000000: str += (reste > 1) ? "milliards" : "milliard de"; break;
        case 1000000: str += (reste > 1) ? "millions" : "million"; break;
        case 1000: str += "mille"; break;
        default: break;
    }
    return str;
}

/**
 *  Traite le montant en toutes lettres avec les séparateurs appropriés et ajoute les unités monétaires.
 *  @montant Valeur entière du montant
 *  @estFranc Booléen pour indiquer s'il s'agit de francs ou de centimes
 *  @return Le montant en toutes lettres avec unités
 **/
string traitementMontant(unsigned long long int montant, bool estFranc) {
    string str;
    unsigned int centaine = 0, dizaine = 0, unite = 0, reste = 0;
    unsigned long long int montantOriginal = montant;

    // Boucle pour traiter chaque tranche de 3 valeurs du montant entré par l'utilisateur
    for (long long int i = 1000000000000; i >= 1; i /= 1000) {
        reste = montant / i;
        if (reste != 0) {
            centaine = reste / 100 % 10;
            dizaine = reste / 10 % 10;
            unite = reste % 10;

            //Permet de rajouter un '-' après mille/millions/milliards/billions lorsque le code repasse dans la boucle
            if (str.empty()) {
                str += '-';
            }

            if (centaine != 0) {
                str += centaineEnLettres(centaine, dizaine, unite, i);
            }
            if (dizaine != 0) {
                str += switchDizaineCaractere(dizaine, unite);
            }

            if (dizaine != 1) {//gère les cas de 10 à 19 pour pas écrire douze deux ou onze un
                str += switchUniteCaractere(unite, i, dizaine, centaine);
            }

            str += switchSuffixe(reste, i);
        }
        montant -= reste * i;
    }

    // Ajout de la bonne unité monétaire : franc/s ou centime/s
    if (estFranc) {
        if (str.empty()) { //gère le cas pour un montant de 0 ou 0.XX
            str += "zero";
        }
        //ajoute la liaison "de" à la fin du string pour les millions, milliards, billions
        if(montantOriginal % 1000000 == 0 && montantOriginal != 0) {
            str +=" de";
        }
        str += (montantOriginal <= 1) ? " franc" : " francs";
    } else {
        str += (montantOriginal <= 1) ? " centime" : " centimes";
    }
    return str;
}

/**
 * Convertit un montant en toutes lettres, gère les francs et centimes séparément.
 * @param montant Le montant à convertir en toutes lettres
 * @return Le montant en toutes lettres avec unité(s) monétaire(s)
 **/
string montantEnToutesLettres(long double montant) {
    constexpr long double MONTANT_MAX = 1000000000000000;
    // Gestion des erreurs
    if (montant < 0) return "erreur : montant negatif";
    if (montant >= MONTANT_MAX) return "erreur : montant trop grand";

    // Multiplier par 100 et arrondir pour obtenir la valeur entière avec les centimes inclus (ex: 123.45 => 12345)
    auto montantTemp = static_cast<long long int>(round(montant * 100));
    //Grâce au tronquage des virgules du type int, on peut diviser par 100 pour ne plus avoir les centimes
    long long unsigned int franc = montantTemp / 100;
    //le modulo 100 permet de garder que le montant qui correspond au centime
    int centime = static_cast<int>(montantTemp % 100);

    string strFrancs = traitementMontant(franc, true);
    string strCentimes = traitementMontant(centime, false);


    if (franc > 0) {
        // si il y a des centimes on concatène les deux montants par un 'et'
        // si non on retourne juste le montant des francs
        return (centime > 0) ? strFrancs + " et " + strCentimes : strFrancs;
    }
    if (centime > 0) {
        return strCentimes;
    }
    return strFrancs;
}
