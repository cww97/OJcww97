program cx;
uses math;
var i,v,n,j,ans:longint;
    ti,va,f:array[0..10000]of longint;

begin
  read(v,n);
  for i:=1 to n do read(ti[i],va[i]);
  for i:=1 to n do
    for j:=v downto ti[i] do
      f[j]:=max(f[j],f[j-ti[i]]+va[i]);
  for i:=0 to v do ans:=max(ans,f[i]);
  writeln(ans);
end.
