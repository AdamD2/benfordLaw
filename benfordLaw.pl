#!/usr/bin/perl -w
#
# Benford's Law Tester - Use input files to test Benford's Law
# 
# Author: Adam Douglas <adam_douglas2@hotmail.com>
#

main();

sub main {
    my %num_count;
    for (my $i = 1; $i <= 9; $i++) {
        $num_count{$i} = 0;
    }

    foreach $num (<>) {
        $indexes++;

        if ($num =~ /[1-9]/) {
            $num =~ s/^([1-9]).*$/$1/;
            print $num;
            $num_count{$num} = $num_count{$num} + 1;
        }
    }

    for (my $i = 1; $i <= 9; $i++) {
        $distribution = ($num_count{$i}/$indexes)*100;
        print "Distribution for $i is $distribution\n";
    }
}
