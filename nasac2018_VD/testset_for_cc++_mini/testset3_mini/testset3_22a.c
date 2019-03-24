
#include "std_testcase.h"

#include <wchar.h>




int testset3_22a_fooGlobal = 0;

void testset3_22a_fooSink(char * data);

void testset3_22a_foo()
{
    char * data;
    
    data = NULL;
    testset3_22a_fooGlobal = 1; 
    testset3_22a_fooSink(data);
}






int CWE476_NULL_Pointer_Dereference__char_22_cwe_bar1Global = 0;
int CWE476_NULL_Pointer_Dereference__char_22_cwe_bar2Global = 0;
int CWE476_NULL_Pointer_Dereference__char_22_cwe_fooGlobal = 0;
int testset3_22a_barB2DBGlobal = 0;


void CWE476_NULL_Pointer_Dereference__char_22_cwe_bar1Sink(char * data);

static void cwe_bar1()
{
    char * data;
    
    data = NULL;
    CWE476_NULL_Pointer_Dereference__char_22_cwe_bar1Global = 0; 
    CWE476_NULL_Pointer_Dereference__char_22_cwe_bar1Sink(data);
}


void CWE476_NULL_Pointer_Dereference__char_22_cwe_bar2Sink(char * data);

static void cwe_bar2()
{
    char * data;
    
    data = NULL;
    CWE476_NULL_Pointer_Dereference__char_22_cwe_bar2Global = 1; 
    CWE476_NULL_Pointer_Dereference__char_22_cwe_bar2Sink(data);
}


void CWE476_NULL_Pointer_Dereference__char_22_cwe_fooSink(char * data);

static void cwe_foo()
{
    char * data;
    
    data = "Good";
    CWE476_NULL_Pointer_Dereference__char_22_cwe_fooGlobal = 1; 
    CWE476_NULL_Pointer_Dereference__char_22_cwe_fooSink(data);
}

void testset3_22a_barB2DBSink(char* data);
static void goodB2DB()
{
	char* data;
	data = NULL;
	testset3_22a_barB2DBGlobal = 0;
	testset3_22a_barB2DBSink(data);
}

void testset3_22a_bar()
{
    cwe_bar1();
    cwe_bar2();
    cwe_foo();
    goodB2DB();
}



