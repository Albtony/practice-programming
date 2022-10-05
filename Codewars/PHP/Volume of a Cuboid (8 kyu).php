<?php
/*
Source: https://www.codewars.com/kata/58261acb22be6e2ed800003a/php
Title: Volume of a Cuboid
Diff: 8 kyu

Instruction
Bob needs a fast way to calculate the volume of a cuboid with three values: the length, width and height of the cuboid. 
Write a function to help Bob with this calculation.
*/

$kata = new class {
    public function get_volume_of_cuboid($length, $width, $height) {
        return $length * $width * $height;
    }
};

function assertEquals($ans, $res) {
    if($ans == $res) echo "true\n";
    else echo "false\n";
}

assertEquals(4, $kata->get_volume_of_cuboid(1, 2, 2));
assertEquals(63, $kata->get_volume_of_cuboid(6.3, 2, 5));
?>