program cx;
var i,xy,max,n:longint;
    a:array[0..1000]of longint;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  max:=0;
  xy:=0;
  for i:=n downto 1 do
    if a[i]>=max then
      begin
        max:=a[i];
        xy:=i;
      end;
  writeln(max,' ',xy);
end.
