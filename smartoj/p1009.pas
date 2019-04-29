program cx;
uses math;
var i,j,n,ans:longint;
    a:array[0..1000,0..1000]of longint;

begin
  read(n);
  for i:=1 to n do
    for j:=1 to i do
      begin
        read(a[i,j]);
        a[i,j]:=a[i,j]+max(a[i-1,j-1],a[i-1,j]);
      end;
  ans:=0;
  for i:=1 to n do ans:=max(ans,a[n,i]);
  writeln(ans);
end.