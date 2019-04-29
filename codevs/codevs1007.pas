program cx;
var i,k:longint;
    gym:real;

begin
  read(k);
  for i:=1 to 1000000 do
    begin
      gym:=gym+(1/i);
      if gym>k then break;
    end;
  writeln(i);
end.