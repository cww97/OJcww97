var a:array[1..3,1..26]of char;
    b:array['A'..'Z']of longint;
    c:array[0..25]of boolean;
    i,j,n:longint;
    judge:boolean;

function check(x,m:longint):boolean;
var yy:boolean;
    i,j:longint;
begin
  if ((b[a[1,x]]+b[a[2,x]]+m)mod n<>b[a[3,x]]) then exit(false);
  for i:=1 to x-1 do
   if (b[a[1,i]]<>-1)and(b[a[2,i]]<>-1)and(b[a[3,i]]<>-1) then
    begin
      yy:=true;
      for j:=0 to 1 do
       if (b[a[1,i]]+b[a[2,i]]+j) mod n=b[a[3,i]] then yy:=false;
       if yy then exit(false);
    end;
   exit(true);
end;

procedure dfs(x,m:longint);
var i,j,d,p,mm:longint;
    aa,bb,cc:boolean;

begin
  if x=0 then
   begin
     if m=0 then
      begin
        for i:=1 to n-1 do write(b[chr(i+64)],' ');
        writeln(b[chr(n+64)]);
        //judge:=true;
        //exit;
        halt;
      end;
      exit;
   end;
   aa:=false;
   bb:=false;
   cc:=false;
   if b[a[1,x]]<>-1 then aa:=true;
   if b[a[2,x]]<>-1 then bb:=true;
   if b[a[3,x]]<>-1 then cc:=true;
   if (aa and bb and cc) then
    begin
      if check(x,m) then dfs(x-1,(m+b[a[1,x]]+b[a[2,x]])div n);
    end
   else if aa and bb then begin
		 	    d:=(b[a[1,x]]+b[a[2,x]]+m)mod n;
			    if c[d] then
				      begin
					b[a[3,x]]:=d;
					c[d]:=false;
					mm:=(b[a[1,x]]+b[a[2,x]]+m)div n;
					if check(x,m) then dfs(x-1,mm);
					c[d]:=true;
					b[a[3,x]]:=-1;
				      end;
                          end
   else if aa and cc then begin
		 	    d:=(b[a[3,x]]-m-b[a[1,x]]+n)mod n;
			    if c[d] then
				      begin
					b[a[2,x]]:=d;
					c[d]:=false;
					mm:=(b[a[1,x]]+d+m)div n;
					if check(x,m) then dfs(x-1,mm);
					c[d]:=true;
					b[a[2,x]]:=-1;
				      end;
                          end
   else if bb and cc then begin
		 	    d:=(b[a[3,x]]-m-b[a[2,x]]+n)mod n;
			    if c[d] then
				      begin
					b[a[1,x]]:=d;
					c[d]:=false;
					mm:=(b[a[2,x]]+d+m)div n;
					if check(x,m) then dfs(x-1,mm);
					c[d]:=true;
					b[a[1,x]]:=-1;
				      end;
                          end
   else if (not aa) and (not bb) and (not cc) then
     begin
       if a[1,x]<>a[2,x] then
        begin
	  for i:=n-1 downto 0 do
           for j:=n-1 downto 0 do
            if (c[i] and c[j])and(i<>j) then
             begin
               c[i]:=false;
               c[j]:=false;
               b[a[1,x]]:=j;
               b[a[2,x]]:=i;
               dfs(x,m);
               c[i]:=true;
               c[j]:=true;
               b[a[1,x]]:=-1;
               b[a[2,x]]:=-1;
             end;
        end
       else for i:=n-1 downto 0 do
              if c[i] then
                begin
		  b[a[1,x]]:=i;
		  c[i]:=false;
		  dfs(x,m);
		  b[a[1,x]]:=-1;
	          c[i]:=true;
                end;
     end
     else begin
       	    for i:=n-1 downto 0 do
             if c[i] then
              begin
		if not aa then p:=1
                 else if not bb then p:=2
                  else if not cc then p:=3;
                b[a[p,x]]:=i;
		c[i]:=false;
		dfs(x,m);
                b[a[p,x]]:=-1;
		c[i]:=true;
              end;
          end;
end;

begin
  readln(n);
   for i:=1 to 3 do
    begin
      for j:=1 to n do
        read(a[i,j]);
        readln;
    end;
  fillchar(b,sizeof(b),255);
  fillchar(c,sizeof(c),true);
  judge:=false;
  dfs(n,0);
end.