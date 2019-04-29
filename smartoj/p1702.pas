program cx;//°ËÊıÂë,Î´Íê³É
const by:array[1..4,1..9]of longint=((0,0,0,1,1,1,1,1,1),
                                     (1,1,1,1,1,1,0,0,0),
                                     (0,1,1,0,1,1,0,1,1),
                                     (1,1,0,1,1,0,1,1,0));
      d:array[1..4]of longint=(-3,3,-1,1);
var i,l0:longint;
    t,target:string;
    ok:boolean;
    a:array[0..1000000]of string;
    v:array['0123456789'..'9876543210']of boolean;

begin
  fillchar(v,sizeof(v),0);
  target:='123804765';
  ok:=false;
  readln(t);
  for i:=1 to 9 do
    if t[i]='0' then
      begin
        l0:=i;
        break;
      end;
  f:=1;
  r:=1;
  a[1]:=t;
  v[a[1]]:=true;
  repeat
    for i:=1 to 4 do
      begin
        if by[l0,i]=0 then continue;
        t:=a[f];
        t[l0]:=t[l0+d[i]];
        t[l0+d[i]]:='0';
        if v[t] then continue;
        inc(r);
        a[r]:=t;
        v[t]:=true;
        ok:=true;
        if t=target then
          begin
            f:=maxlongint;
            break;
          end;
      end;
    if ok then inc(step);
    ok:=false;
    inc(r)
  unitl f>r;
  writeln(step);
end.
