#include <Python.h>
#include "linebreaker.h"

int main(){
	// initialize python interpreter
	Py_Initialize();

	// Import python module
	PyObject* pName = PyUnicode_DecodeFSDefault("hello_module");
	PyObject* pModule = PyImport_Import(pName);
	Py_DECREF(pName);

	if (pModule != NULL) {
		// get the function from the module
		PyObject* pFunc = PyObject_GetAttrString(pModule, "hello");

		if(pFunc && PyCallable_Check(pFunc)) {
			// call the python function
			printf("calling hello function of python hello_module\n");
			PyObject* pRetValue1 = PyObject_CallObject(pFunc, NULL);
			if (pRetValue1 != NULL) {
				printf("Result of Python function 1: %ld\n",PyLong_AsLong(pRetValue1));
				Py_DECREF(pRetValue1);
			} else{
				printf("Failed to execute hello function\n");
			}
		}
		Py_XDECREF(pFunc);

		line_break(20);

		// get another function from the module
		PyObject* pFunc_name = PyObject_GetAttrString(pModule, "hello_name");

		// define arguments
		PyObject* pArgs = PyTuple_Pack(1, PyUnicode_FromString("CJ-404"));

		if (pFunc_name && PyCallable_Check(pFunc_name)) {
			// call to the function
			printf("calling hello_name(name) function of python hello_module\n");
			PyObject* pRetValue2 = PyObject_CallObject(pFunc_name, pArgs);

			if (pRetValue2 == NULL) {
				// print error
				printf("Failed to execute hello_name function\n");
				PyErr_Print();
			} else {
				printf("hello_name function called successfully: void result\n");
				Py_DECREF(pRetValue2);
			}
		}
		Py_XDECREF(pFunc_name);

		
		Py_DECREF(pModule);
	}

	// finalize the python interpreter
	Py_Finalize();

	return 0;
}
