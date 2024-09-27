#define PY_SSIZE_T_CLEAN
#include <Python.h>

float square(float x) { return x * x; }

static PyObject *square_wrapper(PyObject *self, PyObject *args) {
  float input, result;
  if (!PyArg_ParseTuple(args, "f", &input)) {
    return NULL;
  }
  result = square(input);
  return PyFloat_FromDouble(result);
}

static PyMethodDef foo_methods[] = {
    {"square", square_wrapper, METH_VARARGS, "Square function"},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef foo_module = {PyModuleDef_HEAD_INIT, "foo",
                                             NULL, -1, foo_methods};

/* name here must match extension name, with PyInit_ prefix */
PyMODINIT_FUNC PyInit_foo(void) {
  return PyModule_Create(&foo_module);
}
