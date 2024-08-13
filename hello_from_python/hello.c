#include <Python.h>

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
			PyObject* pValue = PyObject_CallObject(pFunc, NULL);
			if (pValue != NULL) {
				printf("Result of Python function: %ld\n",PyLong_AsLong(pValue));
				Py_DECREF(pValue);
			}
		}
		Py_XDECREF(pFunc);
		Py_DECREF(pModule);
	}

	// finalize the python interpreter
	Py_Finalize();

	return 0;
}
