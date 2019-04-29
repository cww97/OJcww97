program cx;
var i,kong,kongkong:longint;
    st,a,b:string;

begin
  readln(st);
  kong:=pos(' ',st);
  for i:=kong+1 to length(st) do
    if st[i]<>' ' then break;
  kongkong:=i-1;
  a:=copy(st,1,kong-1);
  b:=copy(st,kongkong+1,length(st)-kongkong);
  writeln(pos(b,a));
end.
