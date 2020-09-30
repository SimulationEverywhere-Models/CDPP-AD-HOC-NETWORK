[top]
components :  nodep@NodePositions nodegen@NodeGenerator deque@NodeGenerator registry@Registry
out : nout lout

Link : out@nodep pos@registry
Link : aout@registry nout
Link : lout@registry lout
Link : aout@nodegen gen@registry
Link : aout@deque  deq@registry