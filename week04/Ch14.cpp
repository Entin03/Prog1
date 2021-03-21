#include "std_lib_facilities.h"
//FELADAT1
	class B1{
	public:		
		void f()
		{
			cout<<"B1::f \n";
		};
		
		virtual void vf()
		{
			cout<<"B1::vf \n";
		};
//FELADAT5
		virtual void pvf()=0;
	
               };


//FELADAT2
	class D1: public B1
	{
	public:		
//FELADAT4
		void f()
		{
		cout<<"D1::f \n";
		};
		
		void vf() override
		{
		cout<<"D1::vf \n";
		};
		
		void pvf() override
		{
		cout<<"D1::pvf \n";
		}
	};

//FELADAT6
	class D2: public D1
	{
	public:
		void vf() override
		{
		cout<<"D2::vf \n";
		};
		
		void pvf() override
		{
		cout<<"D2::pvf \n";
		};
	};

//FELADAT7
	class B2
	{
	public:
		virtual void pvf()=0;	
	};

	class D21: public B2
	{
	public:
		void pvf() override
		{
		cout<<s<<endl;
		};
	private:
	string s="Yahallo";
	};

	class D22: public B2
	{
	public:
		void pvf() override
		{
		cout<<szam<<endl;
		};
	private:
		int szam=42;
	
	};

	void f(B2 &ba)
	{
	ba.pvf();
	}

int main()
{
	D1 d;
	d.f();
	d.vf();
	d.pvf();
	
	B1 &bref = d;
	bref.f();
	bref.vf();
	bref.pvf();
	
	D2 dd;
	dd.f();
	dd.vf();
	dd.pvf();
	
	D21 ke;
	D22 kk;
	
	f(ke);
	f(kk);
	return 0;
}
