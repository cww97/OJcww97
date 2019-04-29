program cx;
var i,ans,n,l,x,j,fj:longint;
    a:array[0..10000]of longint;
    fo:array[0..1000000]of boolean;

function check(x:longint):boolean;
var i:longint;
begin
  for i:=1 to n do
    begin
      if a[i] > x then exit(true);
      if not fo[x << 1 -a[i]] then exit(false);
    end;
end;

begin
  read(n,l);
  for i:=1 to n do
    begin
      read(a[i]);
      a[i]:=a[i]<< 1;
      fo[a[i]]:=true;
    end;

  for i:=1 to n do
    for j:=1 to n do
      if a[i]<a[j] then
        begin fj:=a[i]; a[i]:=a[j]; a[j]:=fj; end;

  for i:=0 to l << 1 do
    if check(i) then
    begin
     //write(i,' ');
     inc(ans);
    end;
  //writeln;
  writeln(ans);
end.
