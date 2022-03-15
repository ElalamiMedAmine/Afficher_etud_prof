#include <iostream>
#include<string.h>
using namespace std;

class Personne
{
public:
    Personne(string n, string p, int age);
    virtual void afficher() const; //8
private:
    string nom;  //40
    string prenom; //40
    int age; //4

};

Personne::Personne(string n, string p, int age)
{
    this->nom = n;
    this->prenom = p;
    this->age = age;
}

void Personne::afficher() const
{
    std::cout << "nom: " << this->nom << std::endl;
    std::cout << "prenom: " << this->prenom << std::endl;
    std::cout << "age: " << this->age << std::endl;
}


class Etudiant : public virtual Personne
{

public:
    Etudiant(string n, string p, int a, int cne);
     void afficher() const override;

private:
    int cne; //96+8=104
};


Etudiant::Etudiant(string n, string p, int a, int cne)
    : Personne(n, p, a)
{
    this->cne = cne;
}

void Etudiant::afficher() const
{
    this->Personne::afficher();
    std::cout << "cne: " << this->cne << std::endl;
}


class Professeur : public virtual  Personne
{
public:
    Professeur(string n, string p, int a, int mat);
     void afficher() const override;
private:
    int matricule; //88
};


Professeur::Professeur(string n, string p, int a, int mat)
    :Personne(n, p, a)
{
    this->matricule = mat;
}

void Professeur::afficher() const
{
   // this->Personne::afficher();
    std::cout << "matricule: " << this->matricule << std::endl;
}


    class PA : public  Etudiant,public  Professeur
{
public:
    PA(string n, string p, int a, int cne, int matricule, string thema);
    void afficher()const ;

private:
    string thematique;  //40+88=128

};


    PA::PA(string n, string p, int a, int cne, int matricule, string thema) :
        Etudiant(n, p, a, cne), Professeur(n, p, a, matricule), Personne(n, p, a)
    {
        this->thematique = thema;
    }

    void PA::afficher() const
    {
       this->Etudiant::afficher();
        this->Professeur::afficher();
        std::cout << "thematique: " << this->thematique << std::endl;
    }

int main()
{
 
    PA* tst = new PA("a", "m", 20, 56, 10, "fr");
    tst->afficher();
   
}