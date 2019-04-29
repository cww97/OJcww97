# -*- coding: utf-8 -*-
aList = "aāáǎà"
eList = "eēéěè"
iList = "iīíǐì"
oList = 'oōóǒò'
uList = "uūúǔù"
vList = "üǖǘǚǜ"


if __name__ == '__main__':
    T = int(input())
    for cas in range(T):
        print("Case %d: "% (cas+1), end='')
        st = input()
        key = 0
        if st[-1].isdigit():
            key = int(st[-1])
            st = st[:len(st)-1]
        ok =False
        if 'a' in st:
            st = st.replace('a',aList[key])
        elif 'e' in st:
            st = st.replace('e',eList[key])
        elif 'o' in st:
            st = st.replace('o',oList[key])
        elif 'ui' in st:
            st = st.replace('i',iList[key])
        elif 'iu' in st:
            st = st.replace('u',uList[key])
        elif 'i' in st:
            st = st.replace('i',iList[key])
        elif 'u' in st:
            st = st.replace('u',uList[key])
        elif 'v' in st:
            st = st.replace('v',vList[key])
        print(st)