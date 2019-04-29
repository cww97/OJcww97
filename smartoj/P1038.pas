program cx;      //谁拿了最多的奖学金smartoj1038
var i,max,sum,kong,n:longint;
    st,ghk:string;
    name:array[0..1000]of string;
    money,team,class,paper:array[0..1000]of longint;
    west,stu:array[0..1000]of boolean;

begin
  readln(n);
  for i:=1 to n do
    begin
      readln(st);
      kong:=pos(' ',st);
      name[i]:=copy(st,1,kong-1);
      delete(st,1,kong);
      kong:=pos(' ',st);
      val(copy(st,1,kong-1),team[i]);
      delete(st,1,kong);
      kong:=pos(' ',st);
      val(copy(st,1,kong-1),class[i]);
      delete(st,1,kong);
      kong:=pos(' ',st);
      if st[1]='Y' then stu[i]:=true
        else stu[i]:=false;
      delete(st,1,kong);
      kong:=pos(' ',st);
      if st[1]='Y' then west[i]:=true
        else west[i]:=false;
      delete(st,1,kong);
      val(st,paper[i]);
      if (team[i]>80) and (paper[i]>=1) then inc(money[i],8000);
      if (team[i]>85) and (class[i]>80) then inc(money[i],4000);
      if (team[i]>90) then inc(money[i],2000);
      if (team[i]>85) and (west[i]) then inc(money[i],1000);
      if (class[i]>80) and (stu[i]) then inc(money[i],850);
      if money[i]>max then
        begin
          max:=money[i];
          ghk:=name[i];
        end;
      inc(sum,money[i]);
    end;
  writeln(ghk);
  writeln(max);
  writeln(sum);
end.
