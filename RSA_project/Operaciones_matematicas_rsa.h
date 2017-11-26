#include<NTL/ZZ.h>
#include<vector>
using namespace std;
using namespace NTL;
//OPERACIONES MATEMATICAS
ZZ Random_prime(long long b=256){
	return RandomPrime_ZZ(b);
}
ZZ Eucli(ZZ a,ZZ b){
	ZZ tmp;
	while(b!=0){
		tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;
}
ZZ Div_mod(ZZ a,ZZ b,ZZ m=ZZ(0),ZZ x1=ZZ(1),ZZ x2=ZZ(0),ZZ y1=ZZ(0),ZZ y2=ZZ(1)){
	m=Eucli(a,b);
	ZZ c,tmp,tmp1,tmp2;
	ZZ d=b;
	while(b!=m){
		c=a/b;
		tmp=b;
		b=a%b;
		a=tmp;
		tmp1=x1;
		tmp2=x2;
		x1=y1;
		x2=y2;
		y1=tmp1-(c*y1);
		y2=tmp2-(c*y2);
	}
	return y1%d;
}
ZZ Expo_mod(ZZ a,ZZ n,ZZ m){
	ZZ exp=ZZ(1);
	ZZ x=a%m;
	while(n>0){
		if(n % ZZ(2)==ZZ(1))exp=(exp*x)%m;
		x=(x*x) % m;
		n=n/2;
	}
	return exp;
}
vector<ZZ>Bloque(vector<ZZ>vec,int param=20){
	vector<ZZ>nuevo;
	int j;
	ZZ u;
	for(int i=0;i<vec.size();i++){
		j=0;
		u=ZZ(0);
		for(j=0;j<param and i+j<vec.size();j++){
			u=u*ZZ(256)+ZZ(vec[i+j]);
		}
		nuevo.push_back(u);
		i+=j-1;
	}
	return nuevo;
}
vector<ZZ> Desbloque(vector<ZZ>vec){
	vector<ZZ>nuevo;
	for(int i=0;i<vec.size();i++){
		vector<ZZ>res;
		while(vec[i]>ZZ(0)){ 
			res.push_back(vec[i]%ZZ(256));
			vec[i]/=ZZ(256);
		}
		for(int j=res.size()-1;j>=0;j--)nuevo.push_back(res[j]);
	}
	return nuevo;
}
vector<ZZ> caracter(string &p){
	vector<ZZ>nuevo;
	for(int i=0;i<p.size();i++) nuevo.push_back(ZZ(int(p[i])));
	return nuevo;
}
string numero(vector<ZZ>n){
	string u;
	int y;
	for(int i=0;i<n.size();i++) {
		y=conv<int>(n[i]);
		u+=char(y);
	}
	return u;
}
//INPUT AND OUTPUT
string ingresar_mensaje(){
	//string t;
	//getline(cin,t);
	string oracion;
	getline(cin,oracion);
	string h;
	int k=0;
	while(oracion[k]!='\0')h+=oracion[k++];
	return h;
}
vector<ZZ> ingresar_cifrado(){
	string h=ingresar_mensaje();
	ZZ x=ZZ(0);
	vector<ZZ>cifrado;
	for(int i=0;i<h.size();i++){
		if(h[i]!=' '){
			int y=h[i];
			y-=48;
			x=x*ZZ(10)+ZZ(y);
		}
		if(h[i]==' ' or i==h.size()-1){
			cifrado.push_back(x);
			x=ZZ(0);
		}
	}
	return cifrado;
}
void imprimir_cifrado(vector<ZZ>cifrado){
	for(int i=0;i<cifrado.size();i++){
		cout<<cifrado[i];
		if(i==cifrado.size()-1)cout<<endl;
		else cout<<" ";
	}
}
void imprimir_mensaje(string mensaje){
	cout<<mensaje<<endl;
}
//OPERACIONES DE CONVERSION
string ZZ_a_str(ZZ num){
	string p;
	int u;
	char t;
	while(num>ZZ(0)){
		ZZ r=num%ZZ(10);
		u=conv<int>(r);
		u+=48;
		t=u;
		p+=t;
		num/=10;
	}
	for(int i=0;i<p.size()/2;i++){
		t=p[i];
		p[i]=p[p.size()-i-1];
		p[p.size()-i-1]=t;
	}
	return p;
}
ZZ str_a_ZZ(string & p1){
	ZZ e=ZZ(0);
	int y;
	for(int i=0;i<p1.size();i++){
		y=p1[i];
		y-=48;
		e=e*ZZ(10)+ZZ(y);
	}
	return e;
}
string vec_a_str(vector<ZZ>vec){
	string p;
	for(int i=0;i<vec.size();i++){
		p+=ZZ_a_str(vec[i]);
		if(i!=vec.size()-1)p+=' ';
	}
	return p;
}
vector<ZZ> str_a_vec(string p){
	string h;
	vector<ZZ>vec;
	for(int i=0;i<p.size();i++){
		if(p[i]!=' ')h+=p[i];
		if(p[i]==' ' or i==p.size()-1){
			vec.push_back(str_a_ZZ(h));
			string vacio;
			h=vacio;
		}
	}
	return vec;
}
