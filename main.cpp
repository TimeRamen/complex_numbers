#include <iostream>
#include <math.h>
using namespace std;
class Complex{
private:
	float real;
	float imaginary;
public:
	Complex(float r=0, float i=0);
	void setValue(float r=0, float i=0);
	float getReal() const;
	float getimaginary() const;
    void print() const;
    float mod(Complex x);
    float arg(Complex x);
    Complex operator+(const Complex& x) const;
    Complex operator-(const Complex& x) const;
    Complex operator*(const Complex& x) const;
    Complex operator/(const Complex& x) const;
};
class Polar{
private:
    float mod;
    float arg;
public:
    Polar(float m=1,float a=0);
    void setValue(float m=1,float a=0);
    float getMod() const;
    float getArg() const;
    void print() const;
};

Complex::Complex(float r,float i){
    real = r;
    imaginary = i;
}
void Complex::setValue(float r,float i){
    real = r;
    imaginary = i;
}
float Complex::getReal() const{
return real;
}
float Complex::getimaginary() const{
return imaginary;
}

void Complex::print() const{
  if(real!=0){
    if(imaginary>0)
    {   if(imaginary==1){cout<<real<<"+i";}
        else {cout<<real<<"+"<<imaginary<<"i";}}
    if(imaginary<0)
    {   if(imaginary==-1){cout<<real<<"-i";}
        else {cout<<real<<imaginary<<"i";}}
    if(imaginary==0)
    {cout<<real;}}
  if(real==0){
    if(imaginary>0)
    {   if(imaginary==1){cout<<"i";}
        else{cout<<imaginary<<"i";}}
    if(imaginary<0)
    {   if(imaginary==-1){cout<<"-i";}
        else{cout<<imaginary<<"i";}}
    if(imaginary==0)
    {cout<<real;}}
}

Complex Complex::operator+(const Complex& x) const{
  float sumreal = real + x.real;
  float sumimag = imaginary + x.imaginary;
  return Complex(sumreal, sumimag);

}
Complex Complex::operator-(const Complex& x) const{
  float sumreal = real - x.real;
  float sumimag = imaginary - x.imaginary;
  return Complex(sumreal, sumimag);
}
Complex Complex::operator*(const Complex& x) const{
  float sumreal = (real*x.real)-(imaginary*x.imaginary);
  float sumimag = (real*x.imaginary)+(imaginary*x.real);
  return Complex(sumreal, sumimag);
}
Complex Complex::operator/(const Complex& x) const{
  float temp = (x.real*x.real) + (x.imaginary*x.imaginary);
  float sumreal = (real*x.real+imaginary*x.imaginary)/temp;
  float sumimag = (imaginary*x.real-real*x.imaginary)/temp;
  return Complex(sumreal, sumimag);
}

void scanComp(char o, float* i){
switch(o)
  {
  case '+':
  break;
  case '-':
  *i = -*i;
  break;
  default :;
  }
}

float Complex::mod(Complex x){
  float mod;
  float a = (x.real)*(x.real);
  float b = (x.imaginary)*(x.imaginary);
  float c = a + b;
  mod = sqrt(c);
  return (mod);
}
float Complex::arg(Complex x){
  float arg;
  float tangent = x.imaginary/x.real;
  if(x.real>0)
  {arg = atan(tangent);}
  if((x.real<0)&&(x.imaginary>=0))
  {arg = atan(tangent) + M_PI;}
  if((x.real<0)&&(x.imaginary<0))
  {arg = atan(tangent) - M_PI;}
  return arg;
}

int main()
{
Complex a,b,c;
//Complex d(5,6);
float w,x,y,z;
char m,n;
//d.print();

cin>>w>>m>>x>>n;
scanComp(m,&x);
cin>>y>>m>>z>>n;
scanComp(m,&z);

a.setValue(w,x);
b.setValue(y,z);

c = a + b;
c.print();
cout<<endl;

c = a - b;
c.print();
cout<<endl;

c = a * b;
c.print();
cout<<endl;

c = a / b;
c.print();
cout<<endl;

w = a.mod(a);
cout<<w;

return 0;
}
