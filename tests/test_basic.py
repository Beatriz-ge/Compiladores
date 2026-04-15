# tests/test_ast.py
import unittest

class TestAST(unittest.TestCase):

    def test_var_decl(self):
        resultado = "VarDecl(name=x, value=10)"
        self.assertEqual(resultado, "VarDecl(name=x, value=10)")