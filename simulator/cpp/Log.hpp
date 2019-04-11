/**
 * Log system header
 *
 * \author Phileas Fogg
 * \file Log.hpp
 */

#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <map>

#  undef FunctionName
#  define LOG(...)	utils::Out::printInfo( __PRETTY_FUNCTION__,__FILE__,__LINE__,__VA_ARGS__)


/*!
 * \file Log.hpp
 * \brief Affichage de donnees de debug
 * \author Aubin Detrez
 * \version 0.1
 */

/*! \namespace utils
 * 
 * Regroupe les utilitaires, ils ne sont pas specifiques à l'application
 * et peuvent être réutilisés
 */
namespace utils
{
/*! \class Out
 * \brief Gère les sorties
 *
 * La classe permet de gere les sorties de debug
 *
 */
class Out
{
	public:
		template<class... Args>
		/*!
		 *  \brief Affiche un message d'information
		 *
		 *  Ajoute au message le fichier, la fonction et la ligne
		 *  Ainsi que de la couleur dans le cas où le texte commence par
		 *  les mots clefs "Error", "Ok" ou "Test"
		 */
		static void printInfo(const char* fcn,const char* file,int line,const std::string & format, Args&&... args);
	private:
		/*!
		 *  \brief Verifie que une chaine en contient une autre
		 *
		 *  Test si Ref commence par format ou pas
		 *
		 *  \return true si ref contient format, false sinon
		 */
		static bool contain(const std::string & ref,const std::string & format);
};

template<class... Args>
void Out::printInfo(const char* fcn,const char* file,int line,const std::string & format, Args&&... args)
{
    std::string str = "%s, %s, %d:\t\t"+format;
#ifdef __linux__
    if(contain(format,"Error"))
        printf("\033[31m");
    else if(contain(format,"Ok"))
        printf("\033[32m");
    else if(contain(format,"Test"))
        printf("\033[33m");
    else if(contain(format,"Debug"))
        printf("\033[34m");
#endif
#pragma GCC diagnostic ignored "-Wformat-security"
    printf(str.c_str(), file, fcn, line, std::forward<Args>(args)...);
    printf("\033[m\n");
}

} // utils

#endif // LOG_HPP
