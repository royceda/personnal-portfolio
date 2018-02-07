<span class="navigation_p">Page:
<?php
if ($page<2){
	$start=0;
	if ($pages<5 && $pages!=0)
		$end=$pages;
	else if($pages<5 && $pages==0)
		$end=1;
	else
		$end=5;
}
else{
	if ($pages<6){
		$start=0;
		$end=$pages;
	}
	else if($page+2>=$pages){
		$start=$pages-4;
		$end=$pages;
	}

	else{
		$start=$page-2;
		if ($pages<$page+3)
			$end=$pages;
		else $end=$page+3;
	}
}

if ($pages>5 && $page>3){
	?> <a href="?p=<?php echo $start-1?>">&lt;</a>
<?php }
for ($i=$start;$i<$end;$i++){
	if ($i==$page){?>
		<span class="actuel"><?php echo $page?></span>
	
	<?php
	} 
	else {?>
		<a href="?p=<?php echo $i?>"><?php echo $i?></a> 		 
<?php 	}
}
if ($pages>$end+2)	
 echo '<a href="?p='.($end+2).'">...</a>';
if ($pages!=$page && $end!=$pages) 
	echo '<a href="?p='.($page+1).'">&gt;</a>';
?>
</span>