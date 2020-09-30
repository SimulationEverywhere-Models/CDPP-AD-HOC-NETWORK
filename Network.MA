[top]
components : nodmanager stats@NetStats
out : rel
Link : aout@stats rel
Link : nout@nodmanager nin@stats
Link : lout@nodmanager lin@stats

[nodmanager]
components :  nodep@NodePositions registry@Registry
out : nout lout

Link : out@nodep pos@registry
Link : aout@registry nout
Link : lout@registry lout