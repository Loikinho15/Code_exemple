#include <array>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <set>
#include <utility>
#include <vector>
#include <span>
#include <algorithm>
#include <atomic>

#include "MesLibrairies/date.h"
#include "MesLibrairies/jours_entre.h"
#include "MesLibrairies/personne.h"
#include "MesLibrairies/to_string.h"
#include "MesLibrairies/maLibrairie.h"

using namespace std;
//----------------------------------------------- CHAPITRE 3 -----------------------------------------------

//******** CH 3 - Exercice 01-10 ***********
/*int main() {
    double note_UNIGE;

    cout<<"Entrer une note : ";
    cin >> note_UNIGE;

    if (note_UNIGE < 0 || note_UNIGE > 6) {
        cout<<"Erreur";
    } else {
        lround(note_UNIGE);
        if (note_UNIGE < 3.75) {
            cout<<"La note ECTS est : F";
        }
        else if(note_UNIGE < 4.25) {
            cout << "La note ECTS est H"
        }
    }
}*/

//************ CH 3 - Exercice 01-11 ************
/*int main() {
    cout << "Donnez les valeurs de a, b, et c de l'equation a*x^2+b*x+c : ";
    double a, b, c;
    cin >> a >> b >> c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Tout x est une solution" << endl;
            } else {
                cout << "Pas de solution" << endl;
            }
        } else {
            cout << "une seule solution : " << -c/b << endl;
        }
    } else {
        double discriminant = pow(b,2) - 4*a*c;
        if (discriminant < 0) {
            cout << "Pas de solution" << endl;
        } else if (discriminant == 0) {
            cout << "une seule solution : " << - b / 2*a << endl;
        } else {
            double sqrt_discriminant = sqrt(discriminant);
            double reponse1 = (-b + sqrt_discriminant)/(2*a);
            double reponse2 = (-b - sqrt_discriminant)/(2*a);
            cout << "deux solutions possibles : 1) " << reponse1 << " 2) " << reponse2 << endl;
        }

    }
}*/
//************ CH 3 - Exercice 02-03 ************
/*int main () {
    double init_amt = 0;
    cout << "Entrez le montant initial : ";
    cin >> init_amt;

    double target_amt = 0;
    cout << "Entrez le montant cible : ";
    cin >> target_amt;

    double tx_int = 0;
    cout << "Entrez le taux d'interet annuel en % : ";
    cin >> tx_int;

    if (tx_int <= 0 && init_amt < target_amt) {
        cout << "Le montant ne sera jamais atteint";
    } else {
        int i = 0;
        for (i; init_amt < target_amt; ++i) {
            init_amt += (init_amt * (tx_int/100));
        }
        cout << "Le montant cible est atteint après " << i << " années";
    }
}*/

//************ CH.3 - Exercice 02-06 ************
/*int main () {
    double init_amt = 0;
    cout << "Entrez le montant initial : ";
    cin >> init_amt;

    double tx_int = 0;
    cout << "Entrez le taux d'interet annuel en % : ";
    cin >> tx_int;

    double nb_annees = 0;
    cout << "Entrez le nombre d'années : ";
    cin >> nb_annees;

    int i = 0;
    for (i; i < nb_annees; ++i) {
        init_amt += (init_amt * (tx_int/100));
    }
        cout << "Le montant disponible après " << i << " ans est de : " << init_amt << endl;
}*/

//************ CH.3 - Exercice 02-08 ************
/*int main() {
    double init_amt = 0;
    do {
        cout << "Entrez le montant initial : ";
        cin >> init_amt;
    }while (init_amt < 1000);

    double tx_int = 0;
    do {
        cout << "Entrez le taux d'interet annuel en % : ";
        cin >> tx_int;
    }while(tx_int < -5 || tx_int >= 50);

    double nb_annees = 0;
    do {
        cout << "Entrez le nombre d'années : ";
        cin >> nb_annees;
    }while (nb_annees <= 0);


    int i = 0;
    for (i; i < nb_annees; ++i) {
        init_amt += init_amt * (tx_int/100);
    }
    cout << "Le montant disponible après " << i << " ans est de : " << init_amt << endl;
}*/

//************ CH.3 - Exercice 02-09 ************
/*int main() {
    const double g = 9.81;

    double coeff_rebond = 0;
    do {
        cout << "Coefficient de rebond  (0 <= coeff < 1) : ";
        cin >> coeff_rebond;
    }while (coeff_rebond < 0 || coeff_rebond >= 1);

    double hauteur = 0;
    do {
        cout << "Hauteur initiale [m]   (h0 >= 0) : ";
        cin >> hauteur;
    } while (hauteur < 0);

    double nb_rebond = 0;
    do {
        cout << "Nombre de rebonds  (n >= 0) : ";
        cin >> nb_rebond;
    } while (nb_rebond < 0);

    int i = 0;
    for (i; i < nb_rebond; ++i) {
        //la balle tombe
        double vitesse_balle = sqrt(2*g*hauteur);

        //la balle rebondit
        vitesse_balle = coeff_rebond*vitesse_balle;
        hauteur = pow(vitesse_balle,2)/(2*g);
    }

    cout << "Hauteur atteinte après " << i << " rebonds : " << hauteur << endl;
}*/

//************ CH.3 - Exercice 02-11 ************
/*int main () {
    int h = 0;
    do {
        cout << "Hauteur du triangle : ";
        cin >> h;
    } while (h < 0);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < (h - i - 1); j++) {
            cout << " ";
        }
        for (int k = 0; k < (i * 2) + 1 ; k++) {
            cout << "*";
        }
        cout << endl;

    }
    cout << endl;
}*/

//************ CH.3 - Exercice 02-11 ************
/*int main () {
    int a = 0;
    int b = 0;

    do {
        cout << "Entrez deux nombre entier positifs";
        cin >> a >> b;
    } while (a < 0 || b < 0);

    while (a <= 0 or b <= 0);

    // Calcul du ppmc
    int ppmc = a;
    while (ppmc % b != 0)
        ppmc += a;

    // Affichage du résultat
    cout << "ppmc(" << a << "," << b << ") = " << ppmc << endl;
}*/

//---------------------------------------------------------------------------------------------------------


//----------------------------------------------- CHAPITRE 4 -----------------------------------------------

//************ CH.4 - Exercice 02a-03 ************
/*double volumePyramide(double longueur,
                      double largeur,
                      double hauteur) {
    return longueur * largeur * hauteur / 3.0;
}
void afficher(const string& texte,
              double valeur,
              int precision) {
    cout << fixed << setprecision(precision) << texte << valeur << endl;
}
int main() {
    afficher("volume pyramide 1 = ", volumePyramide(10, 3.5, 12), 1);
    afficher("volume pyramide 2 = ", volumePyramide(3.6, 2.4, 2.7), 1); // 7.8
    return EXIT_SUCCESS;
}*/

//************ CH.4 - Exercice 02a-04 ************
/*bool IsBisextile(int annees) {
    return (annees % 400 == 0) || (annees % 4 == 0 && annees % 400 != 0);
}
void test(int annee) {
    cout << annee << " : " << boolalpha << IsBisextile(annee) << endl;
}

int main() {
    test(1900);
    test(2000);
    test(2010);
    test(2020);
}*/

//************ CH.4 - Exercice 02b-02 ************
/*void PermutationCirculaire(double& a, double& b, double& c) {
    double tmp = c;
    c = b;
    b = a;
    a = tmp;
}
int main() {
    double a = 1;
    double b = 2;
    double c = 3;

    cout <<"a : " << a << ", b : " << b << ", c : " << c << endl;
    PermutationCirculaire(a,b,c);
    cout <<"a : " << a << ", b : " << b << ", c : " << c << endl;

 return EXIT_SUCCESS;
}*/

//************ CH.4 - Exercice 02b-04 ************
/*bool Calcul (double x, const char operand, double y, double& val){
    switch (operand) {
        case '+' : val = x + y; break;
        case '-' : val = x - y; break;
        case '*' : val = x * y; break;
        case '/' : val = x / y; break;
        default: return false;
    }
    return true;
}

int main () {
    double x = 0;
    cout << "Veuillez entre une première valeur : " << endl;
    cin >> x;

    char operand;
    cout << "Veuillez choisir l'opération à effectuer : " << endl;
    cin >> operand;

    double y = 0;
    cout << "Veuillez entre une deuxième valeur : " << endl;
    cin >> y;

    double resultat = 0.0;
    if(Calcul(x,operand,y,resultat)) {
        cout << "Resultat: " << resultat << endl;
    } else {
        cout << "l'opérateur " << operand << "est inutilisable." << endl;
    }
}*/

//************ CH.4 - Exercice 04-01 ************
/*int& GetMin(int& a, int& b, int& c) {
    if (a < b && a < c) {
        if (b<a && b<c) {
            return b;
        }
        return a;
    }
        return c;
}

int main() {
    int a = 5;
    int b = 4;
    int c = 3;

    cout << GetMin(a, b, c) << endl;
    GetMin(a, b, c) = 1;

    cout << (GetMin(a, b, c) = 1) << endl;
    int& d = GetMin(a,b,c);

    cout << d << endl;
}*/

//************ CH.4 - Exercice 06-01 ************
/*int main () {
    int val = saisir("Votre saisie ", 0, 10);
    afficher("Votre saisie : ", val );
}*/

//************ CH.4 - Exercice 07-02 ************
/*int main () {
    static int val = 0;
    for (int i = 0; i < 3; ++i) {
        afficher("Appel numéro ", ++val);
    }
}*/

//---------------------------------------------------------------------------------------------------------


//----------------------------------------------- CHAPITRE 5 -----------------------------------------------

//************ CH.5 - Exercice 01-01 ************
/*int main () {
    string file_name;
    cout << "Veuillez saisir le nom du ficher : ";
    getline(cin, file_name);

    ofstream note_eleve_out(file_name, ios::app);
    if (!note_eleve_out) {
        cerr << "Erreur : Fichier introuvable.";
    }

    string line;
    while(getline(cin,line)) {
        if (line == "#exit#") {
            break;
        }
        note_eleve_out << line << "\n";
    }
}*/

//************ CH.5 - Exercice 01-02 ************
/*int main() {
    string file_name;
    cout << "Veuillez saisir le nom du fichier : " << endl;
    getline(cin, file_name);

    ifstream file_in(file_name);

    if (!file_in) {
            cerr << "ERREUR : Fichier introuvable" << endl;
    }

    while (file_in) {
        string str;
        getline(file_in, str);
        cout << str << "\n";
    }
    file_in.close();


    ofstream file_out(file_name, ios::app);
    if (!file_out) {
        cerr << "ERREUR : Fichier introuvable";
    }
    cout << "Vous pouvez ajouter du contenu à votre fichier : " << endl;

    string line;
    while(getline(cin,line)) {
        if (line == "#exit#") {
            break;
        }
        file_out << line << "\n";
    }

}*/

//************ CH.5 - Exercice 02-01 ************
/*int main() {
    string file_name;
    cout << "Veuillez saisir le nom du fichier : " << endl;
    getline(cin, file_name);

    ifstream file_in(file_name);

    if (!file_in) {
        cerr << "ERREUR : Fichier introuvable" << endl;
    }

    while (file_in) {
        string str;
        getline(file_in, str);
        cout << str << "\n";
    }
    file_in.close();

    string file_source_name;
    cout << "Ecrire le nom de fichier source : " << endl;
    getline(cin, file_source_name);

    ofstream file_source(file_source_name, ios::app);
    if (!file_source) {
        cerr << "ERREUR : Fichier introuvable";
    }

    auto cin_buffer = cin.rdbuf();
    cin.rdbuf(file_source.rdbuf());

    ofstream monfichier(file_name, ios::app);

    string line;
    while(getline(cin,line)) {
        if (line == "#exit#") {
            break;
        }
        file_source << line << "\n";
    }
    cin.rdbuf(cin_buffer);
    monfichier.close();
}*/

//************ CH.7 - Ex-supp ************
/*struct Date {
    int day;
    int month;
    int year;
};

void show_date (const Date& date) {
    cout << date.day << "." << date.month << "." << date.year << endl;
}

Date add_days(Date, int) {
    Date date = {6, 11, 2024};
    return date;
}

int main () {
    Date d1 = {};
    d1.day = 5;
    d1.month = 11;
    d1.year = 2024;

    Date d2 = {5, 11, 2024};

    show_date(d1); // 5.11.2024

    Date d3 = add_days(d1, 1);

    show_date(d3); // 6.11.2024

    return 0;
}*/

//************ CH.7 - Exercice 01-04 ************
/*Date afficher_date(const Date& uneDate) {
    return uneDate;
}

void afficher_personne(const Personne& personne) {
    cout << personne.nom << personne.ville << personne.age.jour << personne.age.mois << personne.age.annee << endl;
}


int main() {
    Date uneDate = {30, 10, 2023};
    cout << "une date     : "; afficher_date(uneDate);
    cout << endl << endl;

    Personne anna = {"Anna", "Yverdon", uneDate};
    afficher_personne(anna);

    cout << endl;

    return EXIT_SUCCESS;
}*/

//************ CH.7 - Exercice ************
/*int main() {
    Date d1{31, 1, 1973};
    Date d2{7, 11, 2023};
    cout << jours_entre(d1,d2) << " jours entre " << to_string(d1) << " et " << to_string(d2) << endl;
}*/

//************ CH.7 - Exercice ************
/*enum class Mois {JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT, SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE};

bool est_bissextile(int annee) {
    return (annee % 400 == 0) || (annee % 400 && annee % 100 != 0);
}

int duree_mois(Mois Mois, int annee) {
    switch (Mois) {
        case Mois::FEVRIER : return est_bissextile(annee) ? 29 : 28;
        case Mois::AVRIL : case Mois::JUIN : case Mois::AOUT : case Mois::NOVEMBRE :
            return 30;
        default:
            return 31;
    }
}

int main() {
    cout << duree_mois(2,2024) << "\n";
}*/

//************ CH.7 - Exercice 03-03 ************
/*enum class Direction {HAUT, BAS , GAUCHE, DROITE};

struct Coord {
    int x = 0;
    int y = 0;
};

using Point = Coord;

void deplacer(Point& point, Direction direction) {
    switch(direction) {
        case Direction::BAS : point.y--;
        case Direction::HAUT : point.y++;
        case Direction::DROITE : point.x++;
        case Direction::GAUCHE : point.x--;
    }
}*/

//************ CH.7 - Exercice 03-04 ************
/*enum class Chiffre {ZERO, UN, DEUX, TROIS, QUATRE, CINQ, SIX, SEPT, HUIT, NEUF};

Chiffre next (Chiffre chiffre) {
    return Chiffre( (int)chiffre + 1 % 10 );
}

void afficher (Chiffre chiffre) {
    cout << (int)chiffre;
}

int main() {
    Chiffre a = Chiffre::CINQ;
    Chiffre b = next(a);
    afficher(a);
    cout << (a < b ? " < " : " >= ");	   // CINQ < SIX
    afficher(b);
}*/

//************ CH.8 - Exercice 01-01 ************
/*int main() {
    unsigned char c;


    cout << "Entrez un caractere : ";
    cin >> c;
    cout << endl
         << "Code ASCII de '" << c << "'                   : "
         << (int) c << endl
         << "'" << c << "' est une lettre de l'alphabet    : "
         << (isalpha(c) ? "Vrai" : "Faux") << endl
         << "'" << c << "' est une lettre minuscule        : "
         << (islower(c) ? "Vrai" : "Faux")  << endl
         << "'" << c << "' est un chiffre                  : "
         << (isdigit(c) ? "Vrai" : "Faux") << endl
         << "'" << c << "' est un caractere de ponctuation : "
         << (ispunct(c) ? "Vrai" : "Faux") << endl;
}*/

//************ CH.8 - Exercice 03-02 ************
/*string getStrMedian(const string& str) {
    string strMedian;

    if (!str.empty()) {
        if (str.length() % 2 == 0) {//la longueur du str est paire
            strMedian = str.at(str.length()/2 -1);
        }
        strMedian += str.at(str.length()/2);
    }
    return strMedian;
}

int main() {
    cout << "Mediane ABC : "<< getStrMedian("ABC") << endl;
    cout << "Mediane ABCD : " << getStrMedian("ABCD") << endl;
    cout << "Mediane ABCDE : " << getStrMedian("ABCDE") << endl;
}*/

//************ CH.8 - Exercice 03-02 ************
/*int SwithcRomanNb(const char& c) {
    int val = 0;
    switch (c) {
        case('I'):
            val = 1;
        break;
        case('V'):
            val = 5;
        break;
        case('X'):
            val = 10;
        break;
        case('L'):
            val = 50;
        break;
        case('C'):
            val = 100;
        break;
        case('D'):
            val = 500;
        break;
        case('M'):
            val = 1000;
        break;
        default:
            return 0;
    }
    return val;
}
int RomanNumberToInt(const string& str) {
    int nbConverted = 0;
    int currentVal = 0;
    int nextVal = 0;

    for (int i = 0; i < str.length(); i++) {
        currentVal = SwithcRomanNb(str.at(i));
        if (i + 1 != str.length()) {
            nextVal = SwithcRomanNb(str.at(i+1));
            if (nextVal > currentVal) {
                currentVal = nextVal - currentVal;
                ++i;
            }
        }

        nbConverted += currentVal;
    }
    return nbConverted;
}

int main() {
    string nbRomain;
    cout << "Entrez un chiffre romain : ";
    cin >> nbRomain;

    cout << RomanNumberToInt(nbRomain) << endl;
}*/

//************ CH.8 - Exercice 03-05 ************
/*bool IsPalinfrome(const string& str) {
    for(int i = 0; i < str.length() / 2; i++) {
        if (str.at(i) != str.at(str.length()-i-1)) {
            return false;
        }
    }
    return true;
}

int main () {
    string str;
    do{
        cout << "entrez un mot : " << endl;
        cin >> str;

        if (str == "quitter") {
            break;
        }
        if(IsPalinfrome(str)){
            cout << str << " est un palindrome." << endl;
        } else {
            cout << str << " n'est pas un palindrome." << endl;
        }
    }while (true);
}*/

//************ CH.8 - Exercice 04-02 ************
/*int NbOccurence(const string& str, const string& pattern) {
    int nbOccurence = 0;
    size_t pos = 0;

    while ((pos = str.find(pattern, pos)) != string::npos){
        nbOccurence++;
        pos++;
    }

    return nbOccurence;
}

int main() {
    string str;
    string pattern;

    cout << "Entrez une chaîne de caractères : " << endl;
    getline(cin,str);

    cout << "\nEntrez la suite de caractère à compléter : " << endl;
    getline(cin,pattern);

    cout << "La suite de caractère " << "'" << pattern << "'" << " apparaît " << NbOccurence(str, pattern) << " fois dans la chaîne " << "'" << str << "'";
}*/

//************ CH.8 - Exercice 04-05 ************
/*string remplacer_occurences(string texte, const string& pattern, const string& strToRemplace) {
    size_t pos = 0;
    while ((pos = texte.find(pattern, pos)) != string::npos) {
        texte.replace(pos, pattern.length(), strToRemplace);
        pos += pattern.length();
    }
    return texte;
}

int main() {
    string texte{"Les sanglots longs de violons de l'automne "
                 "bercent mon coeur d'une langueur monotone"};
    cout << texte << endl;
    for (auto p: {pair<string, string>{"on", "ON"},
                  {"on", "o"},
                  {"on", "oin"},
                  {"o", "ooo"}}) {
        cout << remplacer_occurences(texte, p.first, p.second) << endl;
                  }
}*/

//************ CH.8 - Exercice 03-04 ************
/* TODO Compléter
int main() {
    string prenomNom;

    cout << "Entrez votre prenom et votre nom : ";
    getline(cin, prenomNom);

    string prenom = prenomNom.substr(0, prenomNom.find(' '));
    string nom = prenomNom.substr(0, prenomNom.rfind(' '));
    cout << "Votre prenom est : " << prenom << endl;
    cout << "Votre nom est : " << nom << endl;
    cout << "Votre acronyme est : " << prenom.at(0) << nom.at(0) << toupper(nom.at(nom.length()-1)) << endl;

}*/

//************ CH.8 - Exercice 04-04 ************
/*TODO compléter
 int main() {
    string prenomNom;
    cout << "Entrez votre prénom et votre nom : " << endl;
    getline(cin, prenomNom);

    string prenom = prenomNom.substr(0, prenomNom.find(' '));

    cout << prenom;
}*/

//************ CH.9 - Exercice 01-06 ************
/*using Vec3d = array<double,3>;

string to_string(const Vec3d& vector) {
    return(stringstream() << '(' << vector[0] << ',' << vector[1] << ',' << vector[2] << ')').str();
}

Vec3d produit(Vec3d vector, double multiple) {

    for (double& element : vector) {
        element *= multiple; //element est une référence à un valeur dans vector => ça le modifie aussi
    }
    return vector;

}

double produit_scalaire(Vec3d a, Vec3d b) {
    double d = 0;

    for (int i = 0; i < a.size(); i++) {
        d += a[i] * b[i];
    }

    return d;
}

int main() {
    Vec3d a{1., 2., 3.};
    Vec3d b{2., 4., 3.};
    cout << "a = " << to_string(a) << endl
         << "b = " << to_string(b) << endl;

    Vec3d c = produit(a, 2.);
    cout << "c = a*2 = " << to_string(c) << endl;

    cout << "a.b = " << produit_scalaire(a, b)
         << ", a.c = " << produit_scalaire(a, c)
         << ", b.c = " << produit_scalaire(b, c) << endl;

    Vec3d d = produit_vectoriel(a, b);
    cout << "d = a^b = " << to_string(d) << endl;
    cout << "a.d = " << produit_scalaire(a, d)
         << ", b.d = " << produit_scalaire(b, d) << endl;
    TODO compléter
    Vec3d e = produit_vectoriel(a, a);
    cout << "e = a^a = " << to_string(e) << endl;
}*/

//************ CH.9 - Exercice 02-02 ************
/*void my_push_back(vector<int>& vector, int val) {
    vector.resize(vector.size()+1);
    for (size_t i = vector.size()-1; i < vector.size(); i++) {
        vector[i] = val;
    }

    for (int i : vector) {
        cout << i;
    }
    cout << endl;
}

void my_pop_back(vector<int>& vector) {
    vector.resize(vector.size() -1 );
    for (int i : vector) {
        cout << i;
    }
    cout << endl;
}

void my_resize(vector<int>& vector, int valResize) {
    while(vector.size() > valResize) {
        vector.pop_back();
    }
    while (vector.size() < valResize) {
        vector.push_back(0);
    }
    for (int i : vector) {
        cout << i;
    }
    cout << endl;
}

void my_resize(vector<int>& vector, int valResize, int val) {
    while(vector.size() > valResize) {
        vector.pop_back();
    }
    while(vector.size() < valResize) {
        vector.push_back(val);
    }
    for (int i : vector) {
        cout << i;
    }
    cout << endl;
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6};
    my_push_back(v, 7);     // v contient {1, 2, 3, 4, 5, 6, 7}
    my_pop_back(v);         // v contient {1, 2, 3, 4, 5, 6}
    my_pop_back(v);         // v contient {1, 2, 3, 4, 5}
    my_resize(v,3);         // v contient {1, 2, 3}
    my_resize(v,5,1);       // v contient {1, 2, 3, 1, 1}
    my_resize(v,8);         // v contient {1, 2, 3, 1, 1, 0, 0, 0}
}*/

//************ CH.9 - Exercice 02-05 ************
/*string to_string(vector<int>& v) {
    string str = "[";
    for (int i : v) {
        str += std::to_string(i);
    }
    return str + "]";
}

void supprimer_centre(vector<int>& v) {
    if (v.empty()) {
        return;
    }
    if (v.size() % 2 == 0) {//est paire
        for (int i = v.size()-1; i > v.size() / 2; i--) {
            v[i - v.size()/2] = v[i];
        }
        v.resize(v.size() - 2);
    } else {
        for (int i = v.size(); i <= v.size() / 2 + 1; i++) {
            v[i - v.size()/2] = v[i];
        }
        v.resize(v.size() - 1);
    }
}

int main() {
    for (vector<int> v: {vector<int>{},
                         {1},
                         {1, 2},
                         {1, 2, 3},
                         {1, 2, 3, 4},
                         {1, 2, 3, 4, 5},
                         {1, 2, 3, 4, 5, 6}}) {
        cout << to_string(v) << " -> ";
        supprimer_centre(v);
        cout << to_string(v) << endl;
                         }
}*/

//************ CH.9 - Exercice 02-06 ************
/*string to_string (const vector<int>& v) { TODO à compléter
    string result = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            result += ", ";
        result += to_string(v[i]);
    }
    return result += "]";
}

void supprimer_valeur (vector<int>& v, int valToDeleat) {
    int firstIndexFound = 0;
    int lastIndexFound = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == valToDeleat) { //la valeur à supprimer est trouvée
            if (firstIndexFound == 0) { // si c'est le premier index qu'on trouve
                firstIndexFound = i;
            } else { // si non c'est pas le premier, et doit être modifié à chaque fois qu'on en trouve un nouveau
                lastIndexFound = i;
            }
        } else { //la valeur à supprimer n'est pas trouvée
            if (firstIndexFound != 0) {
                if (lastIndexFound == 0) {
                    lastIndexFound = firstIndexFound;
                }
                int FirstIndexToPrint = i;
                //donc on copie tout vers la gauche à partie de l'index qui n'est pas égale à la valeur à supprimer
                //jusqu'à l'index de la dernière valeur trouvée à supprimer
                for (int j = firstIndexFound; j <= lastIndexFound; j++) {
                    v[firstIndexFound] = v[FirstIndexToPrint];
                    ++FirstIndexToPrint;
                }
            }
            firstIndexFound = 0;
            lastIndexFound = 0;
        }
    }

}

int main() {
    for (vector<int> v: {vector<int>{},
                         {2},
                         {1, 2, 2, 2, 3, 1, 2, 4},
                         {2, 3, 4, 3, 2, 1},
                         {2, 2, 2},
                         {5, 4, 3, 2, 1, 2}}) {
        cout << to_string(v) << " -> ";
        supprimer_valeur(v,2);
        cout << to_string(v) << endl;
                         }
}*/

//************ CH.9 - Exercice 02-08 ************
/*int main() {
    string str;
    vector<double> vNotes;

    getline(cin, str);;
    stringstream ss(str);

    string tmp;
    while (getline(ss, tmp, ';')) {
        double note = 0.;
        if (ss >> note) {
            vNotes.push_back(stod(ss.str()));
        } else {
            cout << "Pas une valeur valide " << endl;
        }
    }

    for (double element : vNotes) {
        cout << "vNotes elements : " << element << endl;
    }

    int nbNote = 0;
    double somme = 0;
    for (double note : vNotes) {
        nbNote++;
        somme += note;
    }

    double moyenne = somme / static_cast<double>(vNotes.size());

    cout << fixed << setprecision(2) << "Moyenne : " << moyenne;
}*/

//************ CH.9 - Exercice 04-01 ************
/* TODO à compléter
using Matrice3x3 = array<array<double,3>,3>;
using Vec3 = vector<double>;


string to_string(Matrice3x3& m) {
    stringstream ss;
    ss << "[";
    for (int i = 0; i < m.size(); i++) {
        if (i) {
            ss << "]";
        }
        for (int j = 0; j < m.size(); j++)
            ss << m[i][j] << ", ";
    }
    ss << "]";
    return ss.str();
}

Vec3 produit(Matrice3x3& m, Vec3& v ) {
    Vec3 w = {};

    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m.size() ; j++) {
            w[i] += m[i][j] * v[j];
        }
    }
    return w;
}

int main() {

    Matrice3x3 m = {1, 1, 0, 0, 2, 0, 0, 0, 1};
    Vec3 v = {1, 2, 3};
    Vec3 w = produit(m,v);

    cout << to_string(m) << " * "
         << to_string(v) << " = "
         << to_string(w) << endl;
}*/


//----------------------------------------------- CHAPITRE 10 -----------------------------------------------

//************ CH.10 - Exercice 02-01 ************
/*template <typename  T>
void PermutationCirculaire(T& a, T& b, T& c) {
    T tmp = c;
    c = b;
    b = a;
    a = tmp;
}


int main() {
    double a = 1;
    double b = 2;
    double c = 3;

    cout <<"a : " << a << ", b : " << b << ", c : " << c << endl;
    PermutationCirculaire(a,b,c);
    cout <<"a : " << a << ", b : " << b << ", c : " << c << endl;

    return EXIT_SUCCESS;
}*/

/*
template <typename T>
T& min(T& a, T& b, T& c) {
    if (a < b && a < c) {
        return a;
    }
    if (b<a && b<c) {
        return b;
    }
    return c;
}

int main() {
    int    a = 5;
    int    b = 2;
    int    c = 9;

    double d = 5.0;
    double e = 2.0;
    double f = 9.0;

    cout << min(a, b, c) << endl;
    min(a, b, c) = 1;
    int& min_abc = min(a, b, c);
    cout << min_abc << endl;

    cout << min(d, e, f) << endl;
    min(d, e, f) = 1;
    double& min_def = min(d, e, f);
    cout << min_def << endl;
}*/

//************ CH.10 - Exercice 02-08 ************
/*
template <typename T>
T Somme (const vector<T>& ligne) {
    T resultatSomme;
    for (T note : ligne) {
        resultatSomme += note;
    }
    return resultatSomme;
}

template <typename T>
T Moyenne (const vector<T> ligne) {
    if (ligne.empty()) {
        return T();//retourn la valeur par défaut du type T
    }
    return Somme(ligne) / static_cast<T>(ligne.size());
}

template <typename T, typename Ft>
vector<T> stat (vector<vector<T>> notes, Ft function){
    vector<T> vecResultat;
    vecResultat.reserve(notes.size());

    for (const vector<T>& ligne : notes) {
        vecResultat.push_back(function(ligne));
    }
    return vecResultat;
}

template <typename T>
void Afficher(const vector<T>& v) {
    cout << fixed << setprecision(1);
    cout << "[";
    for (T note : v) {
        cout << note << ", ";
    }
    cout << "]" << endl;
}

int main() {
    const vector<vector<double>> notes {{4.0, 5.0, 6.0},
                         {4.1, 5.1, 4.8},
                         {3.5, 4.1     },
                         {4.5, 4.5, 4.6}};

    auto resultatSomme = stat(notes, Somme<double>);
    Afficher(resultatSomme);
    auto resultatMoyenne = stat(notes, Moyenne<double>);
    Afficher(resultatMoyenne);
}*/

//************ CH.10 - Exercice 03-01 ************
/*struct HeureMinute {
    int heure;
    int minute;
};

ostream& operator<< (ostream& os, const HeureMinute& hm) {
    return os << hm.heure << ":" << hm.minute;
}

istream& operator>> (istream& is, HeureMinute& hm) {
    return is >> hm.heure >> hm.minute;
}

bool operator< (const HeureMinute& hm1, const HeureMinute hm2) {
    if (hm1.heure != hm2.heure) {
        return hm1.heure < hm2.heure;
    }
    return hm1.minute < hm2.minute;
}

bool operator> (const HeureMinute& hm1, const HeureMinute& hm2) {
    if (hm1.heure != hm2.heure) {
        return hm2.heure < hm1.heure;
    } else {
        return hm2.minute < hm1.minute;
    }
}

bool operator<= (const HeureMinute& hm1, const HeureMinute& hm2) {
    return hm1 < hm2;
}

bool operator>= (const HeureMinute& hm1, const HeureMinute& hm2) {
    return hm2 < hm1;
}

bool operator== (const HeureMinute& hm1, const HeureMinute& hm2) {
    return hm1.heure == hm2.heure && hm1.minute == hm2.minute;
}

bool operator!= (const HeureMinute& hm1, const HeureMinute& hm2) {
    return !(hm1 == hm2);
}

HeureMinute operator+ (const HeureMinute& hm1, const HeureMinute& hm2) {
    HeureMinute hm;
    hm.heure = hm1.heure + hm2.heure + (hm1.minute + hm2.minute)/60;
    hm.minute = (hm1.minute + hm2.minute) % 60;

    return hm;
}

HeureMinute operator+ (const HeureMinute& hm1, int val) {
    HeureMinute hm;
    hm.minute = (hm1.minute + val) % 60;
    hm.heure = hm1.heure + (hm1.minute + val) / 60;

    return hm;
}

HeureMinute operator+ (int val, const HeureMinute& hm1) {
    return hm1 + val;
}

HeureMinute& operator+= (HeureMinute& hm1, int val) {
    hm1 = hm1 + val;

    return hm1;
}

HeureMinute& operator++ (HeureMinute& hm1) {
    (hm1.heure += 1) / 60;
    (hm1.minute += 1) % 60;
    return hm1;
}

HeureMinute operator++ (HeureMinute& hm1, int) {
    HeureMinute hm = hm1;
    ++hm1;
    return hm;
}

HeureMinute saisie(const string& msg) {
    HeureMinute hm;
    bool erreur;
    do {
        cout << msg;
        cin >> hm;
        erreur = cin.fail();
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (erreur);
    return hm;
}

int main() {
    HeureMinute hm1 = {12, 34};
    HeureMinute hm2 = {21, 43};

    cout << boolalpha;
    cout << hm1 << " <  " << hm2 << "  : " << (hm1 <  hm2) << endl;
    cout << hm1 << " >  " << hm2 << "  : " << (hm1 >  hm2) << endl;
    cout << hm1 << " <= " << hm2 << "  : " << (hm1 <= hm2) << endl;
    cout << hm1 << " >= " << hm2 << "  : " << (hm1 >= hm2) << endl;
    cout << hm1 << " == " << hm2 << "  : " << (hm1 == hm2) << endl;
    cout << hm1 << " != " << hm2 << "  : " << (hm1 != hm2) << endl;

    cout << hm1 << " +  " << hm2 << "  : " << (hm1 +  hm2) << endl;
    cout << hm1 << " +  " << 44  << "     : " << (hm1 +  44 ) << endl;
    cout << 44  << "    +  " << hm1 << "  : " << (44  +  hm1) << endl;
    cout << hm1 << " += "  << 2 << "      : " << (hm1+=2 )    << endl;

    cout << "++" << hm1  << "\t\t: " << ++hm1 << endl;
    cout << hm1  << "++" << "\t\t: " << hm1++ << endl;
    cout << hm1 << endl;

    cout << endl;
    HeureMinute hm3 = saisie("heure [hh:mm]: ");
    cout << "votre saisie : " << hm3 << endl;
}*/

//----------------------------------------------- CHAPITRE 11 -----------------------------------------------

//************ CH.11 - Exercice 01-01 ************
/*struct Point {
    double x;
    double y;

    void afficher() const{
        cout << "(" << x << "," << y << ")" << endl;
    }

    void deplacer(double x, double y) {
        this->x += x;
        this->y += y;
    }
};

int main() {
    Point centre{};
    centre.afficher();

    Point p{1.2, 2.4};
    p.afficher();
    p.deplacer(0.8, 0.6);
    p.afficher();

    p.x = 5.5;
    p.y = 10.3;
    cout << p.x << " -- " << p.y << endl;
}*/

//************ CH.11 - Exercice 02-01 ************
/*struct Point {
private:
    double x;
    double y;

public:
    void afficher() const{
        cout << "(" << x << "," << y << ")" << endl;
    }
    void deplacer(double x, double y) {
        this->x += x;
        this->y += y;
    }
    double getX() const{
        return x;
    }
    double getY() const{
        return y;
    }
    void setX(double x) {
        this->x = x;
    }
    void setY(double y) {
        this->y = y;
    }
};

int main() {
    Point centre;
    centre.setX(0);
    centre.setY(0);
    centre.afficher();

    Point p;
    p.setX(1.2);
    p.setY(2.4);
    p.afficher();

    p.deplacer(0.8, 0.6);
    p.afficher();

    p.setX(5.5);
    p.setY(10.3);
    cout << p.getX() << " -- " << p.getY() << endl;
}*/

//************ CH.11 - Exercice 03-01 ************
/*class Point {
    double x;
    double y;

public:
    Point(double x, double y): x(x), y(y){}
    Point(): Point(0.,0.){}

    void afficher() const{
        cout << "(" << x << "," << y << ")" << endl;
    }
    void deplacer(double x, double y) {
        this->x += x;
        this->y += y;
    }
    double getX() const{
        return x;
    }
    double getY() const{
        return y;
    }
    void setX(double x) {
        this->x = x;
    }
    void setY(double y) {
        this->y = y;
    }
};

int main() {
    Point centre;
    centre.afficher();

    Point p(1.2,2.4);
    p.afficher();

    p.deplacer(0.8, 0.6);
    p.afficher();

    p.setX(5.5);
    p.setY(10.3);
    cout << p.getX() << " -- " << p.getY() << endl;
}*/

//************ CH.11 - Exercice 03-02 ************
/*class Point {
    double x;
    double y;
    int limX;
    int limY;

public:
    Point(double x, double y, int limX, int limY): x(x), y(y), limX(limX), limY(limY){}
    Point(double x, double y): x(x), y(y), limX(100), limY(100){}

    double getX() const{
        return x;
    }
    double getY() const{
        return y;
    }
    void setX(double x) {
        if (estValide(x)) {
            this->x = x;
        }
    }
    void setY(double y) {
        if (estValide(y)) {
            this->y = y;
        }
    }

    void afficher() const{
        cout << "(" << x << "," << y << ")," << " contrainte: " << "[0," << limX << "]x[" << "0," << limY << "]" << endl;
    }
    void deplacer(double x, double y) {
        setX(x);
        setY(y);
    }
    bool estValide(double val) {
        int maxX = this->limX;
        int maxY = this->limY;

        if (val > maxX || val > maxY) {
            return false;
        }
        return true;
    }
};

int main() {
    Point p1(1.2, 2.4);
    cout << "p1"; p1.afficher();
    p1.deplacer(1., 3.);
    cout << "p1"; p1.afficher();
    p1.setX(4.);
    cout << "p1"; p1.afficher();
    p1.setY(7.);
    cout << "p1"; p1.afficher();

    Point p2(3., 4.2, 10., 10.);
    cout << "p2"; p2.afficher();
    p2.deplacer(15, 2);
    cout << "p2"; p2.afficher();
    p2.deplacer(3, 2);
    cout << "p2"; p2.afficher();
    p2.setX(-3);
    cout << "p2"; p2.afficher();
    p2.setY(12);
    cout << "p2"; p2.afficher();
}*/

//************ CH.11 - Exercice 03-04 ************
/*class Robot {
    int pos;
    int direction = 1;

public:
    Robot(int x);
    Robot();

    int getPosition() const;
    void faireDemiTour();
    void deplacer();
    void deplacer(int x);
};

Robot::Robot(int x): pos(x){}
Robot::Robot():Robot(0){}

int Robot::getPosition() const {
    return pos;
}

void Robot::faireDemiTour() {
    if (direction == 1) {
        direction = -1;
    } else {
        direction = 1;
    }
}

void Robot::deplacer(int x) {
    if (x <= 0) {
        return;
    }
    pos += (x*direction);
}

void Robot::deplacer() {
    pos += direction;
}
int main() {
    Robot r1, r2(10);
    cout << "position courante de r2: " << r2.getPosition() << endl;
    r1.deplacer();
    cout << "position courante de r1: " << r1.getPosition() << endl;
    r1.deplacer(-1);
    cout << "position courante de r1: " << r1.getPosition() << endl;
    r1.deplacer(2);
    cout << "position courante de r1: " << r1.getPosition() << endl;
    r1.faireDemiTour();
    r1.deplacer(4);
    cout << "position courante de r1: " << r1.getPosition() << endl;
    return EXIT_SUCCESS;
}*/

//************ CH.11 - Exercice 03-04 ************
/*class Point {
    double x;
    double y;

public:
    Point(double x, double y): x(x), y(y){}
    Point(): Point(0.,0.){}

    void afficher() const{
        cout << "(" << x << "," << y << ")" << endl;
    }
    void deplacer(double x, double y) {
        this->x += x;
        this->y += y;
    }
    double getX() const{
        return x;
    }
    double getY() const{
        return y;
    }
    void setX(double x) {
        this->x = x;
    }
    void setY(double y) {
        this->y = y;
    }
};

ostream& operator<< (ostream& os, const Point& p) {
    os << "(" << p.getX() << "," << p.getY() << ")" << endl;
    return os;
}
Point operator+ (const Point& p1, const Point& p2) {
    return {p1.getX() + p2.getX(), p1.getY() + p2.getY()};
}
Point operator* (const Point& p1, double d) {
    return {p1.getX() * d, p1.getY()*d};
}
Point operator* (double d, const Point& p1) {
    return p1*d;
}
bool operator== (const Point& p1, const Point& p2) {
    return p1.getX() == p2.getX() && p1.getY() == p2.getY();
}

int main() {
    Point p1(1.2, 2.4);
    Point p2(3., 4.2);

    cout << "p1" << p1 << ", p2" << p2 << endl;

    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p2 + p1 = " << p2 + p1 << endl;

    cout << "p1 * 2. = " << p1 * 2. << endl;
    cout << "3. * p1 = " << 3. * p1 << endl;

    cout << (p1 == p2 ? "p1 == p2" : "p1 != p2") << endl;
    Point p3(p1);
    cout << (p1 == p3 ? "p1 == p3" : "p1 != p3") << endl;
}*/


//************ CH.11 - Exercice 05-01 ************
/*class Point {
    double x;
    double y;
    int limX;
    int limY;
    static int pVal;

public:
    Point(double x, double y, int limX, int limY): x(x), y(y), limX(limX), limY(limY) {
        pVal++;
    }

    Point(double x, double y): Point(x,y, 100, 100){}

    ~Point() {
        pVal--;
    }

    double getX() const{
        return x;
    }
    double getY() const{
        return y;
    }
    void setX(double x) {
        if (estValide(x)) {
            this->x = x;
        }
    }
    void setY(double y) {
        if (estValide(y)) {
            this->y = y;
        }
    }

    void afficher() const{
        cout << "(" << x << "," << y << ")," << " contrainte: " << "[0," << limX << "]x[" << "0," << limY << "]" << endl;
    }
    void deplacer(double x, double y) {
        setX(x);
        setY(y);
    }
    bool estValide(double val) {
        int maxX = this->limX;
        int maxY = this->limY;

        if (val > maxX || val > maxY) {
            return false;
        }
        return true;
    }

    static int getNbPoints() {
        return pVal;
    }
};

int Point::pVal = 0;

int main() {
    Point p1(1.2, 2.4);
    p1.afficher();

    cout << "Nombre de points : " << Point::getNbPoints() << endl;
    cout << "-------------------------------------------" << endl;

    {
        Point p2(3., 4.2, 10., 10.);
        p2.afficher();

        cout << "Nombre de points : " << Point::getNbPoints() << endl;
        cout << "-------------------------------------------" << endl;

        p2 = p1;
        p2.afficher();

        cout << "Nombre de points : " << Point::getNbPoints() << endl;
        cout << "-------------------------------------------" << endl;

        Point p3 = p2;
        p3.afficher();

        cout << "Nombre de points : " << Point::getNbPoints() << endl;
        cout << "-------------------------------------------" << endl;
    }

    Point p4(5, 10);
    p4.afficher();

    cout << "Nombre de points : " << Point::getNbPoints() << endl;
    cout << "-------------------------------------------" << endl;
}*/

//----------------------------------------------- CHAPITRE 12 -----------------------------------------------

//************ CH.12 - Exercice 02-04 ************

/*template <typename T, typename Iterator1, typename Iterator2>
vector<T> concat_tab(Iterator1 first1, Iterator1 last1, Iterator2 first2, Iterator2 last2) {
    vector<T> v;
    v.insert(v.end(), first1, last1);
    v.assign(v.end() ,first2, last2);

    return v;
}

int main () {
    vector<int> vec = {11,12,13};
    array<int, 5> arr = {21,22,23,24,25};
    auto a = concat_tab<int>(vec.begin(), vec.end(), arr.begin(), arr.end());

    // Affichage des éléments concaténés
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}*/

//************ CH.12 - Exercice 02-05 ************
/*template <typename T>
ostream& operator<< (ostream& os, span<T> s) {
    os << "[";
    for (size_t i=0; i<s.size(); ++i) {
        if (i) os << ", ";
        os << s[i];
    }
    return os << "]";
}

template <typename T, typename Iterator1, typename Iterator2>
vector<T> merge (Iterator1 first1, Iterator1 last1, Iterator2 first2, Iterator2 last2) {
    vector<T> v;
    while (first1 != last1 || first2 != last2) {
        if (first1 != last1) {
            v.push_back(*first1);
            ++first1;
        }
        if (first2 != last2) {
            v.push_back(*first2);
            ++first2;
        }
    }
    return v;
}

int main () {
    vector<int> vec = {11,12,13};
    array<int, 5> arr = {21,22,23,24,25};

    auto a = merge<int>(vec.begin(), vec.end(), arr.begin(), arr.end());

    cout << "vector   : " << span<int>(vec) << endl;
    cout << "array    : " << span<int>(arr) << endl;
    cout << "resultat : " << span<int>(a) << endl;
}*/

//************ CH.12 - Exercice 03-02 ************
//foncteur générique
/*template <typename T>
struct entre {
    const T& MIN;
    const T& MAX;

    bool operator() (const T& e) {return e >= MIN && e <= MAX;}
};


int main () {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int MIN = 3;
    const int MAX = 6;

    // avec fonction lambda
    // cout << count_if(v.begin(), v.end(), [MIN, MAX](int val){return val >= MIN && val <= MAX;});

    // avec foncteur
    cout << count_if(v.begin(), v.end(), entre<int>{3,6});
}*/

//************ CH.12 - Exercice 03-04 ************
/*template <typename T>
bool EstIdentique(span<T> a, span<T> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto it1 = unique(a.begin(), a.end());
    auto it2 = unique(b.begin(), b.end());

    for (const T& e : a) {
        if (!find(a.begin(), a.last(), e) != a.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    array<int,10>  a = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2};

    cout << boolalpha << EstIdentique<int>(a,v);
}*/

//----------------------------------------------- CHAPITRE 13 -----------------------------------------------

//************ CH.13 - Exercice 01-01 ************
/*template <typename T>
class Coord {
    T x;
    T y;
public:
    //constructeur
    Coord () : x(0), y(0) {}
    Coord (T x, T y) : x(x), y(y) {}

    void afficher() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    void setCoord (T coordX, T coordY) {
        this->x = coordX;
        this->y = coordY;
    }

    void deplacer (T coordX, T coordY) {
        this->x += coordX;
        this->y += coordY;
    }


    T getX() {
        return this->x;
    }

    T getY() {
        return this->y;
    }
};

int main() {
    cout << "origine  : ";
    const Coord<int> origin;
    origin.afficher();
    cout << endl;

    cout << "p1       : ";
    Coord<int> p1;
    p1.setCoord(1, 2);
    p1.afficher();
    cout << endl;

    cout << "p2       : ";
    Coord<double> p2(3, 4);
    p2.afficher();
    cout << endl;

    cout << "p2->     : ";
    p2.deplacer(1, 1);   // conversion int => double
    cout << "(" << p2.getX() << ", " << p2.getY() << ")";
    cout << endl;
}*/

//************ CH.13 - Exercice 01-02 ************
/*template <typename T>
class Coord {
    T x;
    T y;
public:
    //constructeur
    Coord () : x(T()), y(T()) {}
    Coord (T x, T y) : x(x), y(y) {}

    void afficher() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    void setCoord (T coordX, T coordY) {
        this->x = coordX;
        this->y = coordY;
    }

    void deplacer (T coordX, T coordY) {
        this->x += coordX;
        this->y += coordY;
    }


    T getX() {
        return this->x;
    }

    T getY() {
        return this->y;
    }
};

template <typename T>
class Point {
    string name = "";
    Coord<T> coord;
public:
    Point() : name(), coord(0,0){}
    Point(const string& nom) : name(nom), coord(Coord<T>()){}
    Point(const string& nom, Coord<T> coord) : name(nom), coord(coord){}
    Point(const string& nom, T x, T y) : name(nom), coord(Coord<T>(x, y)){}

    void afficher() {
        cout << this->name <<"(" << this->coord.getX() << ", " << this->coord.getY() << ")";
    }

    string getNom() {
        return this->name;
    }

    void setNom(string nom) {
        this->name = nom;
    }

    Coord<T> getCoord() {
        return this->coord;
    }
    void setCoord(Coord<T> coord) {
        this->coord = coord;
    }

    void deplacer(T x, T y) {
        this->coord.setCoord(x + this->coord.getX(), y + this->coord.getY());

    }
};

int main() {
    const Point<int> origin;

    cout << "p1       : ";
    Point<int> p1("p1"s);
    p1.afficher();
    cout << endl;

    cout << "p2       : ";
    Point<double> p2("p2"s, Coord(1.2, 3.4));
    p2.afficher();
    cout << endl;

    cout << "p3       : ";
    Point<double> p3("p3"s, 1.2, 3.4);
    p3.afficher();
    cout << endl;

    cout << "p3.1     : ";
    p3.setNom("p3.1"s);
    p3.afficher();
    cout << endl;

    cout << "p1(-1, 1): ";
    p1.setCoord(Coord(-1, 1));
    p1.afficher();
    cout << endl;

    cout << "p1->     : ";
    p1.deplacer(-1, 1);
    p1.afficher();
    cout << endl;

    cout << "p1(x)    : ";
    cout << p1.getNom() << " " << p1.getCoord().getX();
}*/

//************ CH.13 - Exercice 01-07 ************
/*
template <typename T, size_t n = 100>
struct Stack {
    size_t taille = 0;
    array<T, n> data;

    void display() const{
        cout << "size   : " << taille << endl;

        cout << "Data   : [";
        for (size_t i = 0; i < taille; i++) {
            if (i != 0){
                cout << ", ";
            }
            cout << data[i];
        }
        cout << "]";
        cout << endl;
    }

    bool full() const{
        return taille == 10;
    }

    void push(T i) {
        if (full()) {
            return;
        }
        data.at(taille) = i;
        ++taille;
    }

    T top() {
        return data.at(taille - 1);
    }

    bool empty() const {
        return taille == 0;
    }

    void pop () {
        data.at(taille - 1) = 0;
        --taille;
    }

    size_t size() const{
        return taille;
    }
};

int main() {
    Stack<int, 10> s;
    int i = 1;

    s.display();
    cout << endl;

    while (not s.full()) {
        s.push(i*=2);
    }

    cout << "top  : " << s.top() << endl;
    cout << "size : " << s.size() << endl;
    cout << endl;

    s.display();
    cout << endl;

    while (not s.empty()) {
        s.pop();
    }

    s.display();
    cout << endl;
}*/

//************ CH.13 - Exercice 01-08 ************
/*template <typename T>
class Coord {
    T x;
    T y;
public:
    //constructeur
    Coord () : x(T()), y(T()) {}
    Coord (T x, T y) : x(x), y(y) {}

    void afficher() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    void setCoord (T coordX, T coordY) {
        this->x = coordX;
        this->y = coordY;
    }

    void deplacer (T coordX, T coordY) {
        this->x += coordX;
        this->y += coordY;
    }


    T getX() {
        return this->x;
    }

    T getY() {
        return this->y;
    }

    template <typename U>
    U distance (const Coord& coord2) {
        U distance;
        distance = sqrt(pow(coord2.x - this->x,2) + pow(coord2.y - this->y,2));
        return distance;
    }
};

template <typename T>
class Point {
    string name = "";
    Coord<T> coord;
public:
    Point() : name(), coord(0,0){}
    explicit Point(const string& nom) : name(nom), coord(Coord<T>()){}
    Point(const string& nom, Coord<T> coord) : name(nom), coord(coord){}
    Point(const string& nom, T x, T y) : name(nom), coord(Coord<T>(x, y)){}

    void afficher() {
        cout << this->name <<"(" << this->coord.getX() << ", " << this->coord.getY() << ")";
    }

    string getNom() const{
        return this->name;
    }

    void setNom(const string& nom) {
        this->name = nom;
    }

    Coord<T> getCoord() const{
        return this->coord;
    }
    void setCoord(Coord<T> coord) {
        this->coord = coord;
    }

    void deplacer(T x, T y) {
        this->coord.setCoord(x + this->coord.getX(), y + this->coord.getY());
    }

    template <typename U>
    U distance(const Point& pt2) {
        const Coord<T>& thisCoord = this->getCoord();
        const Coord<T>& otherCoord = pt2.getCoord();

        return thisCoord.template distance<U>(otherCoord);
    }
};

int main() {
    Point p1("p4", 2,  3);
    Point p2("p5", 7, -1);

    cout << "distance : " << p1.getCoord().distance<double>(p2.getCoord()) << endl;
    cout << "distance : " << p1.distance<double>(p2)                       << endl;
}*/

//************ CH.13 - Exercice 01-07 ************
/*template <typename T, size_t n = 100>
struct Stack {
    size_t taille = 0;
    array<T, n> data;

    void display() const{
        cout << "size   : " << taille << endl;

        cout << "Data   : [";
        for (size_t i = 0; i < taille; i++) {
            if (i != 0){
                cout << ", ";
            }
            cout << data[i];
        }
        cout << "]";
        cout << endl;
    }

    bool full() const{
        return taille == 10;
    }

    void push(T i) {
        if (full()) {
            return;
        }
        data.at(taille) = i;
        ++taille;
    }

    T top() {
        return data.at(taille - 1);
    }

    bool empty() const {
        return taille == 0;
    }

    void pop () {
        data.at(taille - 1) = 0;
        --taille;
    }

    size_t size() const{
        return taille;
    }

    operator string() const{
        string output;
        for (T e: data) {
            output += e;
        }
        return output;
    }
};

int main() {
    Stack<int, 10> s;
    for (int i=0; i<6; ++i) {
        s.push(i);
    }

    // cast Stack<T, n> => string
    cout << string(s) << endl;

    // constructeur par copie
    Stack copie(s);

    // opérateur de flux <<
    //cout << copie     << endl;

    // opérateur ==
    //cout << boolalpha << (s == copie) << endl;
}*/

//----------------------------------------------- CHAPITRE 14 -----------------------------------------------

//************ CH.14 - Exercice 03-02 ************
/*
int sommeNPremiersEntiers(int n);
void test(int n);

int main() {

    test(-1);
    test(0);
    test(1);
    test(65535);
    test(65536);

    return EXIT_SUCCESS;
}

void test(int n) {
    cout << "sommeNPremiersEntiers(" << to_string(n) << ")";
    try {
        cout << " = " << sommeNPremiersEntiers(n) << endl;
    } catch (const exception& e) {
        cout << ": " << e.what() << endl;
    }
}

int sommeNPremiersEntiers(int n) {
    if (n < 0) {
        throw invalid_argument("Argument non valide : n doit être >= 0");
    }
    unsigned long int somme = static_cast<long>(n) * ((n + 1) / 2);
    if (somme > numeric_limits<int>::max()) {
        throw overflow_error("nombre trop grand");
    }
    return static_cast<int>(somme);
}*/

//************ CH.14 - Exercice 03-03 ************
/*
void removeFromVector(std::vector<int>& vec, size_t pos);
int main() {
    vector<int> vector = {1,2,3,4,5,6,7};

    try {
        removeFromVector(vector,4);

        //afficher le vecteur
        for (int e : vector) {
            cout << e << ", ";
        }
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}

void removeFromVector(std::vector<int> &vec, size_t pos) {
    if (pos > vec.size()) {
        throw exception();
    }
    if (vec.empty()) {
        throw runtime_error("vectur vide");
    }

    int readCursor = pos + 1;

    for (size_t i = pos; i < vec.size() - 1; i++) { //lecture
        vec.at(i) = vec.at(readCursor);
        readCursor++;
    }
    vec.pop_back();
}*/

//----------------------------------------------- CHAPITRE 15 -----------------------------------------------

//************ CH.16 - Exercice 01-01 ************
/*class C {
    int i;
public:
    C() : i(0) { cout << "CD " << flush; }
    C(int i) : i(i) { cout << "C" << i << " " << flush; }
    ~C() { cout << "D" << i << " " << flush; }
};

C* f() {
    C* p = new C();

    return p;
}

C* f(int i) {
    C* p = new C{i};

    return p;
}

void g(C* p) {
    delete p;
}

int main() {
    auto p1 = f();
    auto p2 = f(2);
    g(p2);
    p2 = f(3);
    g(p1);
    g(p2);
}*/

//************ CH.16 - Exercice 01-02 ************
/*
class C {
    int i;
public:
    C() : i(0) { cout << "CD " << flush; }
    C(int i) : i(i) { cout << "C" << i << " " << flush; } ~C() { cout << "D" << i << " " << flush; }
};

void* f() {
    return ::operator new(sizeof(C));
}

void f(void* ptr) {
    new(ptr) C;
}

void f(void* ptr, int i) {
    new(ptr) C{i};
}

void g(C* ptr) {
    ptr->~C();
}

int main() {
    void *p1 = f(), *p2 = f();
    f(p1);
    f(p2,4);
    g((C*)p2);
    f(p2,1);
    g((C*)p1);
    ::operator delete(p1);
    g((C*)p2);
    ::operator delete(p2);
}*/

//*********************************************
/*void afficher(span<int> v) {
    for (int e : v) {
        cout << e << ' ' ;
    }
    cout << endl;
}

void tri_a_bulle(span<int> v) {
    size_t end = v.size();
    bool change = true;
    while (change) {
        change = false;
        for (size_t i = 1; i < end; i++) {
            if (v[i] < v[i-1]) {
                swap(v[i], v[i-1]);
                afficher(v);
                change = true;
            }
        }
        --end;
    }
}

int main() {
    vector<int> v = {7,9,4,2,6,3};
    afficher(v);
    tri_a_bulle(v);
}*/


//----------------------------------------------- EX SUPP -----------------------------------------------
//************ CH.99 - Exercice 99-08 ************
#include <iostream>
#include <vector>
using namespace std;

struct Routeur {
    int intensiteSignal; // Intensité du signal du routeur
};

using Reseau = vector<vector<Routeur>>;

Reseau consoliderSignal(const Reseau& reseau) {
    Reseau nouveauReseau;

    for (size_t i = 0; i < reseau.size(); i++) {
        vector<Routeur> nouvelleLigne; // Réinitialiser la ligne à chaque itération
        int totalLeftCol = 0, diviseurLeftCol = 0;
        int totalRightCol = 0, diviseurRightCol = 0;

        for (size_t j = 0; j < reseau[i].size(); j++) {
            // Calcul pour colonnes gauche et droite
            if (j <= 1) { // Colonnes 0 et 1
                totalLeftCol += reseau[i][j].intensiteSignal;
                diviseurLeftCol++;
            } else { // Colonnes 2 et 3
                totalRightCol += reseau[i][j].intensiteSignal;
                diviseurRightCol++;
            }
        }


        // Calcul des moyennes pour chaque côté
        if (diviseurLeftCol > 0) {
            int moyenneLeft = totalLeftCol / diviseurLeftCol;
            nouvelleLigne.push_back({moyenneLeft});
        }
        if (diviseurRightCol > 0) {
            int moyenneRight = totalRightCol / diviseurRightCol;
            nouvelleLigne.push_back({moyenneRight});
        }

        // Ajout de la ligne consolidée au nouveau réseau
        nouveauReseau.push_back(nouvelleLigne);
    }
    return nouveauReseau;
}

int main() {
    Reseau reseau = {
        {{90}, {80}, {70}, {60}},
        {{80}, {70}, {60}, {50}},
        {{70}, {60}, {50}, {40}},
        {{60}, {50}, {40}, {30}},
        {{50}, {40}, {30}, {20}}
    };

    Reseau nouveauReseau = consoliderSignal(reseau);

    // Imprimer le nouveau réseau
    for (const auto& ligne : nouveauReseau) {
        for (const auto& routeur : ligne) {
            cout << routeur.intensiteSignal << " ";
        }
        cout << endl;
    }

    return 0;
}
