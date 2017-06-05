#!/usr/bin/perl -w
#
# Benford's Law Tester - Use input files to test Benford's Law
# 
# Author: Adam Douglas <adam_douglas2@hotmail.com>
#

$version = "Benford's Law Tester version: 0.1.\n";
$help = "Usage: ./benfordLaw.pl [-v] [-h] < data.txt\n" .
        "v - Version\nh - Help\ndata.txt is any text file to test\n";

main();

sub calculate_distribution() {
    my %num_count;

    # Initialize the hash to zero
    for (my $i = 1; $i <= 9; $i++) {
        $num_count{$i} = 0;
    }

    # Load in each number
    foreach $num (<>) {
        $indexes++;

        if ($num =~ /^[1-9]/) {
            $num =~ s/^([1-9]).*$/$1/;
            $num =~ s/\s*$//;
            $num_count{$num} = $num_count{$num} + 1;
        }
    }

    # Print distributions for each number
    for (my $i = 1; $i <= 9; $i++) {
        $distribution = ($num_count{$i}/$indexes)*100;
        print "Distribution for $i is $distribution\n";
    }
}

sub main {
    # Process arguments
    foreach $arg (@ARGV) {
        if ($arg eq "-v" or $arg eq "--version") {
            print $version;
            exit;
        } elsif ($arg eq "-h" or $arg eq "--help") {
            print $help;
            exit;
        }
    }

    # Calculate the distribution for any input
    calculate_distribution();    
}
