class VarDecl:
    def __init__(self, name, value=None):
        self.name = name
        self.value = value

    def __repr__(self):
        return f"VarDecl(name={self.name}, value={self.value})"