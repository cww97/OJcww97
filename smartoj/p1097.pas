program cx;
var n,l:longint;
    i,j:longint;
    ok:boolean;

begin
  //assign(input,'p1097.in');  reset(input);
  //assign(output,'p1097.out');rewrite(output);
  read(n);
  for i:=1 to n do
    begin
      read(l);
      ok:=false;
      if not odd(l) then writeln(1)
      else
        begin
          for j:=2 to trunc(sqrt(l))+1 do
            if l mod j=0 then
              begin
                writeln(j - 1);
                ok:=true;
                break;
              end;
          if not ok then writeln(l - 1);
        end;
    end;
  //close(input);
  //close(output);
end.
