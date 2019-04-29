program cx;
uses math;
var i,n,ans,j:longint;
    a,f,g:array[0..1000]of longint;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
    begin f[i]:=1; g[i]:=1; end;

  for i:=2 to n do
    for j:=1 to i-1 do
      if a[j]<a[i] then f[i]:=max(f[i],f[j]+1);

  for i:=n-1 downto 1 do
    for j:=n downto i+1 do
      if a[j]<a[i] then g[i]:=max(g[i],g[j]+1);

  ans:=0;
  for i:=1 to n do ans:=max(ans,f[i]+g[i]-1);
  writeln(n-ans);
end.
