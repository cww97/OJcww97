program cx;
var i,xy,max,x,y:longint;
    a:array[1..7]of longint;

begin
  for i:=1 to 7 do
    begin
      read(x,y);
      a[i]:=x+y;
    end;
  max:=0;
  xy:=0;
  for i:=1 to 7 do
    if (a[i]>8)and(a[i]>max) then
      begin
        max:=a[i];
        xy:=i;
      end;
  if max=0 then writeln(0)
  else writeln(xy);
end.
