program cx;
var i,x,rainbow,winter:longint;
    y:double;

begin
  read(x,y);
  rainbow:=trunc(x*y/10);
  winter:=rainbow div 10 * 10 ;
  if rainbow mod 10 >=5 then rainbow:=winter + 10
    else rainbow:=winter;
  writeln(rainbow);
end.
