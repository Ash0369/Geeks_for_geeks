def getMinMax( a, n):
    max=0
    min=1e8
    for i in a:
        if(i<min):
            min=i
        if(i>max):
            max=i
    return min,max
