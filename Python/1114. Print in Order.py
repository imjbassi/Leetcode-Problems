from threading import Lock, Condition

class Foo(object):
    def __init__(self):
        self.locks = (Lock(), Lock())
        self.locks[0].acquire()  # Lock for first() is initially acquired
        self.locks[1].acquire()  # Lock for second() is initially acquired
        

    def first(self, printFirst):
        """
        :type printFirst: method
        :rtype: void
        """
        printFirst()
        self.locks[0].release()  # Release the lock for first()
        

    def second(self, printSecond):
        """
        :type printSecond: method
        :rtype: void
        """
        with self.locks[0]:
            printSecond()
            self.locks[1].release()  # Release the lock for second()


    def third(self, printThird):
        """
        :type printThird: method
        :rtype: void
        """
        with self.locks[1]:
            printThird()