
digit 	[0-9]
letter	[a-zA-Z]
number  {I}|{R}|"true"|"false"
I       [+,-]?({digit})+
R 		[+,-]?({digit})+\.({digit})+
Ident	{letter}+{digit}*[{letter}{digit}]*
%{
	#include <iostream>
	#include <string.h>
	void yyerror(char *);
	using namespace std;
	#define ABSTRACT 1
	#define ASSERT 2
	#define BOOLEAN 3
	#define BREAK 4
	#define BYTE 5
	#define CASE 6
	#define CATCH 7
	#define CHAR 8
	#define CLASS 9
	#define CONST 10
	#define CONTINUE 11
	#define DEFAULT 12
	#define DO 13
	#define DOUBLE 14
	#define ELSE 15
	#define ENUM 16
	#define EXTENDS 17
	#define FINAL 18
	#define FINALLY 19
	#define FLOAT 20
	#define FOR 21
	#define GOTO 22
	#define IF 23
	#define IMPLEMENTS 24
	#define IMPORT 25
	#define INSTANCEOF 26
	#define INT 27
	#define INTERFACE 28
	#define LONG 29
	#define NATIVE 30
	#define NEW 31
	#define PACKAGE 32
	#define PRIVATE 33
	#define PROTECTED 34
	#define PUBLIC 35
	#define RETURN 36
	#define SHORT 37
	#define STATIC 38
	#define STRICTFP 39
	#define SUPER 40
	#define SWITCH 41
	#define SYNCHRONIZED 42
	#define THIS 43
	#define THROW 44
	#define THROWS 45
	#define TRANSIENT 46
	#define TRY 47
	#define VOID 48
	#define VOLATILE 49
	#define ASSIGNMENT 50
	#define ADD		51
	#define SUB		52
	#define MULT    53
	#define DIV     54
	#define AND 	55
	#define OR 		56
	#define NOT 	57
	#define EQUAL   58
	#define NOTEQ   59
	#define LESS	60
	#define LESSEQ  61
	#define GREATER 62
	#define GREATEREQ 63
	#define SCOLON  64
	#define COLON 	65
	#define DOT     66
	#define OPENP	67
	#define CLOSEP  68
	#define OPENB   69
	#define CLOSEB	70
	#define OPENK	71
	#define CLOSEK  72
	#define ID      73
	#define NUM     74
	#define KEYW	75
	#define ERROR   76
	#define STRING	77
	int nchar=0,  nword=0, nline=1;

	string aa[100]={"abstract","assert","boolean","break","byte","case","catch","char","class","const","continue","default","do","double","else","enum","extends","final","finally","float","for","goto","if","implements","import","instanceof","int","interface","long","native","new","package","private","protected","public","return","short","static","strictfp","super","switch","synchronized","this","throw","throws","transient","try","void","volatile"};

	string st="";
	int last=0;



	
%}
%%
"abstract"										{	nword++;	return ABSTRACT;}
"assert"										{	nword++;	return ASSERT;}
"boolean"										{	nword++;	return BOOLEAN;}
"break"											{	nword++;	return BREAK;}
"byte"											{	nword++;	return BYTE;}
"case"											{	nword++;	return CASE;}
"catch"											{	nword++;	return CATCH;}
"char"											{	nword++;	return CHAR;}
"class"											{	nword++;	return CLASS;}
"const"											{	nword++;	return CONST;}
"continue"										{	nword++;	return CONTINUE;}
"default"										{	nword++;	return DEFAULT;}
"do"											{	nword++;	return DO;}
"double"										{	nword++;	return DOUBLE;}
"else"											{	nword++;	return ELSE;}
"enum"											{	nword++;	return ENUM;}
"extends"										{	nword++;	return EXTENDS;}
"final"											{	nword++;	return FINAL;}
"finally"										{	nword++;	return FINALLY;}
"float"											{	nword++;	return FLOAT;}
"for"											{	nword++;	return FOR;}
"goto"											{	nword++;	return GOTO;}
"if"											{	nword++;	return IF;}
"implements"									{	nword++;	return IMPLEMENTS;}
"import"										{	nword++;	return IMPORT;}
"instanceof"									{	nword++;	return INSTANCEOF;}
"int"											{	nword++;	return INT;}
"interface"										{	nword++;	return INTERFACE;}
"long"											{	nword++;	return LONG;}
"native"										{	nword++;	return NATIVE;}
"new"											{	nword++;	return NEW;}
"package"										{	nword++;	return PACKAGE;}
"private"										{	nword++;	return PRIVATE;}
"protected"										{	nword++;	return PROTECTED;}
"public"										{	nword++;	return PUBLIC;}
"return"										{	nword++;	return RETURN;}
"short"											{	nword++;	return SHORT;}
"static"										{	nword++;	return STATIC;}
"strictfp"										{	nword++;	return STRICTFP;}
"super"											{	nword++;	return SUPER;}
"switch"										{	nword++;	return SWITCH;}
"synchronized"									{	nword++;	return SYNCHRONIZED;}
"this"											{	nword++;	return THIS;}
"throw"											{	nword++;	return THROW;}
"throws"										{	nword++;	return THROWS;}
"transient"										{	nword++;	return TRANSIENT;}
"try"											{	nword++;	return TRY;}
"void"											{	nword++;	return VOID;}
"volatile"										{	nword++;	return VOLATILE;}
{digit}+{Ident}+						    	{	nword++;	return ERROR;}
{number}										{	nword++; 	return NUM;}
{Ident}+										{	nword++;   	return ID;}
\"[^"\\\n\t]*\"				        			{	nword++;	return STRING;}
=												{	nword++;	return ASSIGNMENT;}
\+												{	nword++;	return ADD;}
-												{	nword++;	return SUB;}
\*												{	nword++;	return MULT;}
\/												{	nword++;	return DIV;}
&&												{	nword++;	return AND;}
\|\|											{	nword++;	return OR;}
!												{	nword++;	return NOT;}
==												{	nword++;	return EQUAL;}
!=												{	nword++;	return NOTEQ;}
\<												{	nword++;	return LESS;}
\<=												{	nword++;	return LESSEQ;}
>												{	nword++;	return GREATER;}
>=												{	nword++;	return GREATEREQ;}
;												{	nword++;	return SCOLON;}
,												{	nword++;	return COLON;}
\.												{	nword++;	return DOT;}
\(												{	nword++;	return OPENP;}
\)												{	nword++;	return CLOSEP;}
\[												{	nword++;	return OPENB;}
\]												{	nword++;	return CLOSEB;}
\{												{	nword++;	return OPENK;}
\}												{	nword++;	return CLOSEK;}
[ \t]											;
\n 												{ 	nline++; 	nword=0; nchar=1;}
.												{	nword++; 	return ERROR;}
"/*"((\*+[^/*])|([^*]))*\**"*/"					{ 	cout << "comment" << endl;}
%%
int yywrap(void) {
	return 1;
}
int main(void) {
	int res;
	bool dd=false;
	do{
		res = yylex();
		if(last != 0){
		if(res != last){
			cout << st <<" : ERROR : " << " : l : " << nline << "  w : " << nword  << " c : " << nchar <<  endl;
			last=0;
			dd=false;
			st="";
		}
	}
		
		if(res == ASSIGNMENT) 	cout<<yytext<<"	:assignment";
		else if(res == ABSTRACT) 	cout<<yytext<<"	:abstract keyword ";
		else if(res == ASSERT) 	cout<<yytext<<"	:assert keyword ";
		else if(res == BOOLEAN) 	cout<<yytext<<"	:boolean keyword ";
		else if(res == BREAK) 	cout<<yytext<<"	:break keyword ";
		else if(res == BYTE) 	cout<<yytext<<"	:byte keyword ";
		else if(res == CASE) 	cout<<yytext<<"	:case keyword ";
		else if(res == CATCH) 	cout<<yytext<<"	:catch keyword ";
		else if(res == CHAR) 	cout<<yytext<<"	:char keyword ";
		else if(res == CLASS) 	cout<<yytext<<"	:class keyword ";
		else if(res == CONST) 	cout<<yytext<<"	:const keyword ";
		else if(res == CONTINUE) 	cout<<yytext<<"	:continue keyword ";
		else if(res == DEFAULT) 	cout<<yytext<<"	:default keyword ";
		else if(res == DO) 	cout<<yytext<<"	:do keyword ";
		else if(res == DOUBLE) 	cout<<yytext<<"	:double keyword ";
		else if(res == ELSE) 	cout<<yytext<<"	:else keyword ";
		else if(res == ENUM) 	cout<<yytext<<"	:enum keyword ";
		else if(res == EXTENDS) 	cout<<yytext<<"	:extends keyword ";
		else if(res == FINAL) 	cout<<yytext<<"	:final keyword ";
		else if(res == FINALLY) 	cout<<yytext<<"	:finally keyword ";
		else if(res == FLOAT) 	cout<<yytext<<"	:float keyword ";
		else if(res == FOR) 	cout<<yytext<<"	:for keyword ";
		else if(res == GOTO) 	cout<<yytext<<"	:goto keyword ";
		else if(res == IF) 	cout<<yytext<<"	:if keyword ";
		else if(res == IMPLEMENTS) 	cout<<yytext<<"	:implements keyword ";
		else if(res == IMPORT) 	cout<<yytext<<"	:import keyword ";
		else if(res == INSTANCEOF) 	cout<<yytext<<"	:instanceof keyword ";
		else if(res == INT) 	cout<<yytext<<"	:int keyword ";
		else if(res == INTERFACE) 	cout<<yytext<<"	:interface keyword ";
		else if(res == LONG) 	cout<<yytext<<"	:long keyword ";
		else if(res == NATIVE) 	cout<<yytext<<"	:native keyword ";
		else if(res == NEW) 	cout<<yytext<<"	:new keyword ";
		else if(res == PACKAGE) 	cout<<yytext<<"	:package keyword ";
		else if(res == PRIVATE) 	cout<<yytext<<"	:private keyword ";
		else if(res == PROTECTED) 	cout<<yytext<<"	:protected keyword ";
		else if(res == PUBLIC) 	cout<<yytext<<"	:public keyword ";
		else if(res == RETURN) 	cout<<yytext<<"	:return keyword ";
		else if(res == SHORT) 	cout<<yytext<<"	:short keyword ";
		else if(res == STATIC) 	cout<<yytext<<"	:static keyword ";
		else if(res == STRICTFP) 	cout<<yytext<<"	:strictfp keyword ";
		else if(res == SUPER) 	cout<<yytext<<"	:super keyword ";
		else if(res == SWITCH) 	cout<<yytext<<"	:switch keyword ";
		else if(res == SYNCHRONIZED) 	cout<<yytext<<"	:synchronized keyword ";
		else if(res == THIS) 	cout<<yytext<<"	:this keyword ";
		else if(res == THROW) 	cout<<yytext<<"	:throw keyword ";
		else if(res == THROWS) 	cout<<yytext<<"	:throws keyword ";
		else if(res == TRANSIENT) 	cout<<yytext<<"	:transient keyword ";
		else if(res == TRY) 	cout<<yytext<<"	:try keyword ";
		else if(res == VOID) 	cout<<yytext<<"	:void keyword ";
		else if(res == VOLATILE) 	cout<<yytext<<"	:volatile keyword ";
		else if(res == ADD) 	cout<<yytext<<"	:ADD";
		else if(res == SUB) 	cout<<yytext<<"	:SUB";
		else if(res == MULT) 	cout<<yytext<<"	:Multiply";
		else if(res == DIV) 	cout<<yytext<<"	:Devide";
		else if(res == AND)		cout<<yytext<<"	:And";
		else if(res == OR) 		cout<<yytext<<"	:OR";
		else if(res == NOT) 	cout<<yytext<<"	:Not";
		else if(res == EQUAL) 	cout<<yytext<<"	:Equal";
		else if(res == NOTEQ) 	cout<<yytext<<"	:NotEqual";
		else if(res == LESS) 	cout<<yytext<<"	:Less Than";
		else if(res == LESSEQ) 	cout<<yytext<<"	:Less Than or Equal";
		else if(res == GREATER) cout<<yytext<<"	:Greater Than";
		else if(res == GREATEREQ) cout<<yytext<<" :Greater Than or Equal";
		else if(res == SCOLON) 	cout<<yytext<<" :semi colon";
		else if(res == COLON) 	cout<<yytext<<"	:colon";
		else if(res == DOT) 	cout<<yytext<<"	:dot";
		else if(res == OPENP) 	cout<<yytext<<"	:open prantess";
		else if(res == CLOSEP) 	cout<<yytext<<"	:close ptantess";	
		else if(res == OPENB) 	cout<<yytext<<"	:open braket";
		else if(res == CLOSEB) 	cout<<yytext<<"	:close braket"; 
		else if(res == OPENK) 	cout<<yytext<<"	:open koroshe";
		else if(res == CLOSEK) 	cout<<yytext<<"	:close koroshe";
		else if(res == INT)		cout<<yytext<<"	:integer constant";
		else if(res == ID)		cout<<yytext<<"	:ID";
		else if(res == STRING)	cout<<yytext<<"	:string";
		else if(res == KEYW)    cout<<yytext<<"	:keyword";
		else if(res == ERROR)	{
				st+=yytext;
				last = res;
				dd = true;
		}
		else if(res == NUM)     cout<<yytext<<"	:number";
		if(dd==false){
			cout << " : l : " << nline << "  w : " << nword  << " c : " << nchar <<  endl;
		}
		nchar+=strlen(yytext);
	}
	while(res);	
	return 0;
}