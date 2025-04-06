class Stack:

    # Error handling system for class
    def perror(self, e):
        print(e)
        except_type = type(e).__name__
        print(f"Error occured in execution: {e}")
        return None

    # constructor 
    def __init__(self):
        try:
            self.container = []
        except Exception as e:
            self.perror(e)
        else: 
            return None

    # destructor (clears stack)
    def clear(self):
        try:
            self.container = []
        except Exception as e:
            self.perror(e)
        else:
            return None

    # push a value to the stack
    # data as argument
    # returns none
    def push(self, data):
        try:
            self.container.append(data)
        except Exception as e:
            self.perror(e)
        else:
            return None
    
    # pop a value from stack
    # data as argument
    # returns none
    def pop(self):
        try:
            self.container.pop()
        except Exception as e:
            self.perror(e)
        else:
            return None
    
    # pop a value from stack
    # data as argument
    # returns none
    def pull(self):
        try:
            value = self.container[-1]
            self.container.pop()
        except Exception as e:
            self.perror(e)
        else:
            return value

    # return element on stack
    # takes no params
    def peek(self):
        try:
            return self.container[-1]
        except Exception as e:
            self.perror(e)