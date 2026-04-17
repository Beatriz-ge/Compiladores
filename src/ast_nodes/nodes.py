class VarDecl:
    def __init__(self, name, value=None):
        self.name = name
        self.value = value

    def __repr__(self):
        return f"VarDecl(name={self.name}, value={self.value})"

class Return:
    def __init__(self, value):
        self.value = value

    def __repr__(self):
        return f"Return(value={self.value})"

class Block:
    def __init__(self, statements):
        self.statements = statements

    def __repr__(self):
        return f"Block(statements={self.statements})"

class MainNode:
    def __init__(self, body):
        self.body = body

    def __repr__(self):
        return f"MainNode(body={self.body})"