                                          //exercice1:
#include<iostream>
using namespace std;
	class Myclass{
	public:
		Myclass(); //constructeur
	   ~Myclass(); //destructeur
	};
	Myclass::Myclass()
	{
		cout<<"cest moi le constructeur"<<endl;
}
	Myclass:: ~Myclass()
	{
		cout<<"c'est moi' le destructeur"<<endl;
}
int main()
{
	Myclass H;
	cout<<"fin"<<endl;
	}
                                             //exercice2:
#include <iostream>
using namespace std;

class shape //creation du classe shape 
{
private:
    double largeur, hauteur;
public:
    //  constructeur
    shape(double nvlargeur, double nvhauteur){
        this->largeur=nvlargeur;
        this->hauteur=nvhauteur;
    }
    double getlargeur() const
    {
        return largeur;
    }
    double gethauteur() const
    {
        return hauteur;
    }
};

 //  de sous classe rectangle 
class Rectangle: public shape
{
public:
   
    Rectangle(double largeur, double hauteur):shape(largeur,hauteur)
    {

    }
    double area()
    {
        return (getlargeur()*gethauteur());
    }
};

 //  de sous classe rectangle 
class Triangle: public shape
{
public:
    Triangle(double base, double hauteur): shape(base,hauteur)
    {

    }
    double area()
    {
        return (getlargeur()*gethauteur())/2.0;
    }
};

int main ()     //definir un rectangle et un triangle
{
    Rectangle rectangle(5.0,3.0);
    Triangle triangle(2.0,5.0);
    cout <<"Area du rectangle est: "<< rectangle.area() << endl; //appel a la fonction area dans les deux classe 
    cout <<"Area du triangle est: "<< triangle.area() << endl;

    system("pause");
    return 0;
}
                                               //exercice3:
//  Programme C++ pour ajouter deux nombres complexes
 

#include<bits/stdc++.h>
using namespace std;
  
// definir une classe complex 
class Complex {
  
    // Declaration des  variables
    public:
        int real, imaginary;
  
    // Constructeur
    // la partie reel et la partie imaginaire
    Complex(int tempReal = 0, int tempImaginary = 0)
    {
        real = tempReal;
        imaginary = tempImaginary;
    }
  
    // definir la methode addComp() 
    // pour ajouter 2 nombres complexes 
    Complex addComp(Complex C1, Complex C2)
    {
        // creer un variable temporaire
        Complex temp;
  
        // ajouter la partie reel a un nombre
        temp.real = C1.real + C2.real;
  
        // ajouter la partie imaginaire a un nombre
        temp.imaginary = C1.imaginary + C2.imaginary;
  
        // retourner la somme
        return temp;
    }
};
  
// La fonction principale main
int main()
{
 
    // le premier nombre  complexe
    Complex C1(3, 2);
 
    // afficher le premier nombre complexe
    cout<<"le nombre complexe numero 1 : "<< C1.real
                << " + i"<< C1.imaginary<<endl;
 
    // le deuxieme nombre complexe
    Complex C2(9, 5);
 
    // afficher le deuxieme nombre complexe
    cout<<" le nombre complexe numero  2 : "<< C2.real
                << " + i"<< C2.imaginary<<endl;
 
    // pour stocker la somme
    Complex C3;
 
    // faire appelle a la methode addComp() 
    C3 = C3.addComp(C1, C2);
 
    // afficher la somme 
    cout<<" la somme des nombres complexes est : "
                       << C3.real << " + i"
                       << C3.imaginary;
}
 
                                    //exercice4:
#include <iostream>
using namespace std;
//clasase mere 
class mere{
public:
	void display ()
	{
		cout << "mere:  fonction display \n";
	}
};
//classe fille herite 
class fille : public mere{
public:
	void display ()
	{
		cout << "fille: fonction display \n\n";
	}
};

int main ()
{
	fille rita;   //definier la fille
	rita.display();    //appel a la methode display()
}
                                     //exercice5:
#include <iostream>
#include <string>
using namespace std;
class Animal
{
	protected:
	 //declaration des membres de la classe  mere "animal"
	 string nom;
	 int age;
	public:
	 void set_value (int a, string n) //dclaration de la methode set_value 
	 {
		age = a;
		nom = n;
	 }


};


class Zebra:public Animal{  //declaration sous classe zebra
public:
void displayZebraMessage()
{
cout<< "le nom du zebra est  "<<nom<<".  et son age est"<< age << " ans  \n";}
};


class Dolphin: public Animal //declaration sous classe dolphin
{
public:


void displayDolphinMessage() 
{
cout<< "le nom du dolphin est :  "<< nom<< ". et son age est  "<<age << "ans /n";}
};
                                                //exercice6:
#include<iostream>
using namespace std;
class Personne{ //declaration de la classe personne
	private:
		string nom;
		string prenom;
		string dt;
    public:
    	Personne(string nom,string prenom,string dt)
{ 
this->nom=nom;
this->prenom=prenom;
this->dt=dt;
}
virtual void afficher()
{ 
cout<<"nom="<<nom<<"prenom="<<prenom<<"dt="<<dt;
}
};
class Employe:public Personne //declaration de la classe employe qui derive la classe personne 
{
protected:
	float salaire;
	public:
		Employe(string nom,string prenom,string dt,float salaire):Personne(nom,prenom,dt)
{
	this->salaire=salaire;
}
virtual void afficher(){
	Personne::afficher();
cout<<"salaire="<<salaire;
}
};
class Chef:public Employe //declaration de la classe chef qui derive la classe employe
{
protected:
	string service;
	public:
		Chef(string nom,string prenom,string dt,float salaire,string service):Employe(nom,prenom,dt,salaire)
{
	this->service=service;
}
virtual void afficher(){
	Employe::afficher();
cout<<"service="<<service;
}
};
class Directeur:public Chef //declaration de la classe directeur qui derive la classe chef 
{
protected:
	string societe;
	public:
		Directeur(string nom,string prenom,string dt,float salaire,string service,string societe):Chef(nom,prenom,dt,salaire,service)
{
	this->societe=societe;
}
virtual void afficher(){
	Chef::afficher();
cout<<"societe="<<societe;
}
};

int main()

{
	int i;
	Personne *T[4];
	T[0]=new Personne("Kessabi\n","Salma\n","16/04/2002\n\n\n");
	T[1]=new Employe("Lazrak\n","hamza\n","01/01/1999\n",2000);
	T[2]=new Chef("Dupon\n","Monique\n","01/05/2001\n",2000,"abc\n\n\n");
	T[3]=new Directeur("Mesrar\n","Nadias\n","27/07/2000\n",2000,"abc\n","rtg\n\n\n");
	
	for (i=0;i<4;i++)
	T[i]->afficher();
	}
	                         //exercice7
    #include<iostream>
#include<cmath>
using namespace std;
class vecteur3d {
	float x;
	float y;
	float z;
	
	public:
	
	//Constructeur d'initialisation
	vecteur3d(float a = 0, float b = 0, float c = 0) : x(a), y(b), z(c) {
	}
	
	//Constructeur de recopie
	vecteur3d(const vecteur3d & v) {
		x = v.x;
		y = v.y;
		z = v.z;		
	}
	
	//L'affichage d'un vecteur
	void afficher() {
		cout << "("<<x<<","<<y<<","<<z<<")" << endl;
	}
	
	//La somme de deux vecteur
	vecteur3d somme(const vecteur3d & v) {
		vecteur3d s;
		s.x = x + v.x;
		s.y = y + v.y;
		s.z = z + v.z;
		return s;
		//Ou return vecteur3d(x+v.x, y+v.y, z+v.z);
	}
	
	//Le produit scalaire de deux vecteurs
	float produit(const vecteur3d & v) {
		return x*v.x + y*v.y + z*v.z;
	}
	
	//tester si deux vecteurs ont les memes composantes
	bool coincide(const vecteur3d & v) {
		return (x == v.x && y == v.y && z == v.z);
	}
	
	//Retourner la norme du vecteur
	float norme() {
		return sqrt(x*x + y*y + z*z);
	}
	
	//Retourner le vecteur qui la plus grande norme : par valeur
	vecteur3d normax(vecteur3d v) {
		if( this->norme() > v.norme())
		    return *this;
		    
		return v;
	}
	
	//Retourner le vecteur qui la plus grande norme : par adresse
	vecteur3d * normax(vecteur3d * v) {
		if( this->norme() > v->norme())
		    return this;
		    
		return v;
	}
	
	//Retourner le vecteur qui la plus grande norme : par reference
	vecteur3d & normaxR(vecteur3d &v) {
		if( this->norme() > v.norme())
		    return *this;
		    
		return v;
	}
};

int main() {
	vecteur3d v1(1,2,3);
	cout << "Vecteur V1";
	v1.afficher();
	vecteur3d v2(5,6,7);
	cout << "Vecteur V2";
	v2.afficher();
	cout<<endl;
	cout << "La somme des vecteurs v1 et v2 est : ";
	(v1.somme(v2)).afficher();
	cout << "Le produit scalaire des vecteurs v1 et v2 est : " << v1.produit(v2) << endl;
	cout<<endl;
	cout << "Copier le vecteur V1 dans V3:" << endl;
	vecteur3d v3(v1);
	cout << "Vecteur V3";
	v3.afficher();
	if(v1.coincide(v3))
	    cout << "Les vecteurs v1 et v3 coincident " << endl; 
	else
	    cout << "Les vecteurs v1 et v3 ne coincident pas " << endl;
	
	cout<<endl;
	cout << "Le vecteur qui a la plus grande norme est (par valeur): ";
	(v1.normax(v2)).afficher();
	cout << "Le vecteur qui a la plus grande norme est (par adresse): ";
	(v1.normax(&v2))->afficher();
	cout << "Le vecteur qui a la plus grande norme est (par reference) :";
	(v1.normaxR(v2)).afficher();
	cout<<endl;
}
                                   
