#include<iostream>
#include<cmath>
using namespace std;

class Term;
class Polynomial;

class Term {
private:
	float Coeff;
	int Exp;
	Term* Next;
public:
	friend class Polynomial;
	Term(float = 0, int = 0, Term* = NULL);
	void Print();
};

class Polynomial {
private:
	Term* Head;
	int Size;
public:
	Polynomial();
	Polynomial(const Polynomial&);
	~Polynomial();
	void InsertTerm(float, int); 
	void Print();
	Polynomial Add(Polynomial);
	Polynomial Multiply(Polynomial);
	float Evaluate(float);
	Polynomial& operator=(const Polynomial&);
	Polynomial operator+(const Polynomial&);
	Polynomial operator*(const Polynomial);
	void Input();
};

void main() {
	cout<< "\n--------------------------------------------------------------------------------------------\n"
		<< "\n                                           Welcome                                          \n"
		<< "\n--------------------------------------------------------------------------------------------\n\n\n";
	cout << "\n~Creating a new Polynomial~\n";
	Polynomial Poly;
	Poly.Input();

	cout << "\n~Polynomial created successfully~\nAs Follows\nPolynomial 1 :\t";
	Poly.Print();

	cout << "\n~Creating a new Polynomial~\n";
	Polynomial Poly2;
	Poly2.Input();

	cout << "\n~Polynomial created successfully~\nAs Follows\nPolynomial 2 :\t";
	Poly2.Print();

	cout << "\n\n\n~Sum of Polynomial 1 and Polynomial 2~";

	Polynomial Poly3 = Poly + Poly2;
	cout << "\n~Polynomial sum created successfully~\nAs Follows\nPolynomial 3 :\t";
	Poly3.Print();

	cout << "\n\n\n~Product of Polynomial 1 and Polynomial 2~";

	Polynomial Poly4 = Poly * Poly2;
	cout << "\n~Polynomial product created successfully~\nAs Follows\nPolynomial 4 :\t";
	Poly4.Print();

	float index;
	cout << "\n\n\n~Evaluation of Polynomials~\n";
	cout << "Enter value for unknown :\t";
	cin >> index;
	cout << "\nPolynomial 1 :\t" << Poly.Evaluate(index) << endl;
	cout << "\nPolynomial 2 :\t" << Poly2.Evaluate(index) << endl;
	cout << "\nPolynomial 3 :\t" << Poly3.Evaluate(index) << endl;
	cout << "\nPolynomial 4 :\t" << Poly4.Evaluate(index) << endl;

	cout << "\nThat's All. Thank You.\n";
}

//---------------------------------------------------------------------------------------
//class Term
Term::Term(float x, int y, Term* ptr) {
	//constructor
	Coeff = x;
	Exp = y;
	Next = ptr;
}

void Term::Print() {
	//printing single term
	cout << Coeff << "n^" << Exp << " ";
}

//---------------------------------------------------------------------------------------
//class Polynomial
Polynomial::Polynomial() {
	//constructor
	Head = NULL;
	Size = 0;
}

Polynomial::Polynomial(const Polynomial& P) {
	//copy constructor for deep copy
	Size = P.Size;
	Term* temp = new Term;
	Head = temp;
	Term* temp2 = P.Head;
	for (; temp2 != NULL ; temp = temp->Next, temp2 = temp2->Next ) {
		//copying till end
		temp->Coeff = temp2->Coeff;
		temp->Exp = temp2->Exp;
		temp->Next = new Term;			//creating new term in advance
	}

}

Polynomial::~Polynomial() {
	//destructor
	Term* Temp = Head;
	Term* Temp2 = Temp->Next;

	for (; Temp != NULL; ) {			
		//keeping record of the next term to delete
		Temp2 = Temp->Next;
		delete Temp;
		Temp = Temp2;
	}
}

void Polynomial::InsertTerm(float Value, int Expo) {
	Term* New = new Term(Value, Expo);

	if (Head == NULL) {
		//if no element
		Head = New;
		Size++;
		return;
	}

	Term* Temp = Head;
	Term* Temp_Next = Head->Next;

	for (int i = 0; i < Size; i++, Temp = Temp->Next , Temp_Next = Temp_Next->Next) {
		if (Temp->Exp == New->Exp) {
			//when exponents are equal
			Temp->Coeff += New->Coeff;
			return;
		}
		else if ((Temp->Exp < New->Exp) && Temp == Head) {
			//when exponent is larger than head
			New->Next = Head;
			Head = New;
			Size++;
			return;
		}
		else if (Temp->Exp > New->Exp) {
			//when exponent is smaller
			New->Next = Temp->Next;
			Temp->Next = New;
			Size++;
			return;
		}
	}
}

void Polynomial::Print() {
	//printing polynomial
	Term* Temp = Head;

	for (int i = 0; i < Size; i++, Temp = Temp->Next) {
		//loop till size
		if (i != 0 && Temp->Coeff > 0)//check if it needs a plus
			cout << "+";
		Temp->Print();//print that term, prints '-' when coefficient is negative
	}
}

Polynomial Polynomial::Add(Polynomial P) {
	//adding two polynomials
	Polynomial Sum;

	//simply inserting becuase insert sorts and adds same ones 

	Term* Temp = Head;
	//poly 1
	for (int i = 0; i < Size; i++, Temp = Temp->Next)
		Sum.InsertTerm(Temp->Coeff, Temp->Exp);

	Temp = P.Head;
	//poly 2
	for (int i = 0; i < P.Size; i++, Temp = Temp->Next)
		Sum.InsertTerm(Temp->Coeff, Temp->Exp);

	return Sum;
}

Polynomial Polynomial::Multiply(Polynomial P) {
	//multiply two polynomials 

	Polynomial Product;
	int i = 0;
	for (Term* Temp = Head; i < Size; i++, Temp = Temp->Next) {
		//for first poly
		Term* Temp2 = P.Head;
		int j = 0;
		for (; j < P.Size; j++, Temp2 = Temp2->Next) {
			//for second poly
			Product.InsertTerm(Temp->Coeff * Temp2->Coeff, Temp->Exp + Temp2->Exp);
		}
	}

	return Product;
}

float Polynomial::Evaluate(float Value) {
	//evaluating polynomial

	Term* Temp = Head;
	float sum = 0;
	for (int i = 0; i < Size; i++, Temp = Temp->Next) {
		//adding each term's solution 
		sum += pow(Value, Temp->Exp) * Temp->Coeff;
	}
	return sum;
}

Polynomial& Polynomial::operator=(const Polynomial& P)
{
	//overloaded assignment operator '=' for deep copy

	if (&P != this) {
		//check if this already is same
		Size = P.Size;
		Term* Temp = new Term;
		Head = Temp;
		Term* Temp2 = P.Head;
		for (; Temp2 != NULL; Temp = Temp->Next, Temp2 = Temp2->Next) {
			//loop till end
			//deep copy
			Temp->Coeff = Temp2->Coeff;
			Temp->Exp = Temp2->Exp;
			Temp->Next = new Term;//adding new term respectively
		}		
	}
	return *this;
}

Polynomial Polynomial::operator+(const Polynomial& P)
{
	//overloaded '+' operator for Add
	Polynomial One = *this;
	Polynomial Two = P;
	Polynomial Sum = Two.Add(One);
	return Sum;
}

Polynomial Polynomial::operator*(const Polynomial P) {
	//overloaded '*' operator for Multiply
	Polynomial One = *this;
	Polynomial Two = P;
	Polynomial Product = Two.Multiply(One);
	return Product;
}

void Polynomial::Input() {
	//for complete input of one polynomial
	float _Coeff;
	int _Exp;
	int check;
	cout << "\nEnter size of Polynomial:\t";
	cin >> check;

	if (check <= 0) {
		cout << "\nWrong Entry. Try Again.\n";
		system("pause");
	}

	for (int i = 0; i < check; i++) {
		cout << "\nEnter Coefficient of " << i + 1 << " value\t";
		cin >> _Coeff;
		cout << "\nEnter Exponent of " << i + 1 << " value\t";
		cin >> _Exp;
		InsertTerm(_Coeff, _Exp);
	}
}
