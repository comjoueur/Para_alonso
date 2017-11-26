#include "Cifrador.h"
void Cifrar_RSA(pair<string,string>lla_pu,string & mensaje){
	RSA rsa;
	rsa.llave_publica.first=str_a_ZZ(lla_pu.first);
	rsa.llave_publica.second=str_a_ZZ(lla_pu.second);
	RSA_cifrador cifrador(rsa.llave_publica);
	cifrador.set_mensaje(mensaje);
	cifrador.cifrar();
	rsa.cifrado=cifrador.get_cifrado();
	mensaje=vec_a_str(rsa.cifrado);
}
void Descifrar_RSA(pair<string,string>lla_pri,string & cifrado){
	RSA rsa;
	rsa.llave_privada.first=str_a_ZZ(lla_pri.first);
	rsa.llave_privada.second=str_a_ZZ(lla_pri.second);
	RSA_descifrador descifrador(rsa.llave_privada);
	rsa.cifrado=str_a_vec(cifrado);
	descifrador.set_cifrado(rsa.cifrado);
	descifrador.descifrar();
	cifrado=descifrador.get_mensaje();
}
pair<pair<string,string>,pair<string,string> > Generar_llave_RSA(){
	CalculoRSA cal;
	RSA rsa;
	rsa.llave_publica=cal.get_llave_publica();
	rsa.llave_privada=cal.get_llave_privada();
	pair<string,string>llave_pu;
	llave_pu.first=ZZ_a_str(rsa.llave_publica.first);
	llave_pu.second=ZZ_a_str(rsa.llave_privada.second);
	pair<string,string>llave_pri;
	llave_pri.first=ZZ_a_str(rsa.llave_privada.first);
	llave_pri.second=ZZ_a_str(rsa.llave_privada.second);
	return make_pair(llave_pu,llave_pri);
}
