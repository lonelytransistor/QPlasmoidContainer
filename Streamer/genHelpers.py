def generateMaxes(maxValue):
    ret  = "#pragma once"
    ret += "\n"
    ret += "\n"
    ret += "#define MAX(X,Y) X>Y ? X:Y"
    ret += "\n"
    ret += "#define MAX2(p0,p1) MAX(p0,p1)"
    ret += "\n"

    ix = 3
    while ix<maxValue:
        pars = 'p'+',p'.join([str(x) for x in range(0,ix-1)])
        lastPar = 'p'+str(ix)
        
        out  = "#define MAX"
        out += str(ix)
        out += "("
        out += pars + "," + lastPar
        out += ") MAX("
        out += "MAX" + str(ix-1) + "(" + pars + "),"
        out += lastPar + ")"
        ret += out + "\n"
        
        ix += 1
    ret += "\n"
    ret += "\n"
    ret += "#define _COUNT(p" + ',p'.join([str(x) for x in range(0,maxValue+2)]) + ", ...) p" + str(maxValue+1)
    ret += "\n"
    ret += "#define COUNT(...) _COUNT(d0, d1, ## __VA_ARGS__ ," + ','.join([str(x) for x in range(maxValue-1,-1,-1)]) + ")"
    ret += "\n"
    ret += "\n"
    ret += "#define __MAXN(a,b) a ## b"
    ret += "\n"
    ret += "#define _MAXN(a,b) __MAXN(a,b)"
    ret += "\n"
    ret += "#define MAXN(...) _MAXN(MAX, COUNT(__VA_ARGS__))(__VA_ARGS__)"
    ret += "\n"
    return ret

with open("Macros.h", "w") as f:
    f.write(generateMaxes(50))
