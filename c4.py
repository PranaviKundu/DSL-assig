def linear_search(nums, target):
    comparisons = 0
    for i in range(len(nums)):
        comparisons += 1
        if nums[i] == target:
            return i, comparisons
    return -1, comparisons

def binary_search(nums, target):
    comparisons = 0
    low = 0
    high = len(nums) - 1

    while low <= high:
        comparisons += 1
        mid = (low + high) // 2

        if target == nums[mid]:
            return mid, comparisons
        elif target < nums[mid]:
            high = mid - 1
        else:
            low = mid + 1
    
    return -1, comparisons

if __name__ == "__main__":
    size = int(input("Enter the size of the array: "))
    
    nums = []
    print("Enter the elements of the array:")
    for i in range(size):
        num = int(input())
        nums.append(num)

    target = int(input("Enter the number you want to search for: "))

    index_linear, comparisons_linear = linear_search(nums, target)
    index_binary, comparisons_binary = binary_search(nums, target)

    if index_linear != -1:
        print(f"(Linear Search) Target {target} found at index: {index_linear}. Comparisons made: {comparisons_linear}")
    else:
        print(f"(Linear Search) Target {target} not found in the list. Comparisons made: {comparisons_linear}")

    if index_binary != -1:
        print(f"(Binary Search) Target {target} found at index: {index_binary}. Comparisons made: {comparisons_binary}")
    else:
        print(f"(Binary Search) Target {target} not found in the list. Comparisons made: {comparisons_binary}")
#first array
#[231 469 177 798 305 564 589 507 544 276 401 625 150 330 207 153 599 685
#  358 103 627 437 111 553 409 768 706 576 411 293 245 343 448 295 552 704
#  711 487 290 346 262 330 254 615 489 188 158 386 499 501 369 560 163 299
#  430 478 689 542 106 723 683 420 784 432 321 174 601 269 493 625 529 274
#  149 462 344 362 795 415 291 354 399 625 446 219 438 414 594 500 177 419
#  383 739 289 113 655 700]
#second array
# [409 769 459 321 125 553 422 103 147 295 292 624 248 683 164 434 313 562
#  425 362 557 796 312 322 439 190 663 239 724 570 149 509 531 170 171 684
# 262 301 167 748 567 307 155 471 128 523 102 174 387 149 251 340 428 186
#  219 163 577 509 637 385 471 206 567 516 195 598 122 513 640 418 420 100
#  372 284 202 187 621 667 575 758 108 598 407 533 180 330 198 652 131 372
#  122 447 133 103 518 455 675 152 163 745 640 370 454 600 409 602 607 244
#  437 505 515 262 548 528]
#third array
# [761 133 521 291 246 191 620 383 385 177 565 128 214 797 606 507 622 588
#  759 481 124 529 203 271 442 632 358 451 613 477 120 624 266 388 627 720
#  247 616 239 593 299 636 176 249 787 145 605 282 728 796 361 125 188 515
#  689 401 467 476 433 470 212 552 781 263 309 137 221 118 627 426 597 565
#  589 565 241 306 561 135 525 290 447 451 278 788 383 306 616 769 212 738
#  248 320 363 518 280 705 414 688 795 540 276 315 379 608 651 794 604 330
#  732 219 533 282 256 233]
#forth array
# [115 601 722 759 606 403 494 206 745 576 769 485 586 772 446 197 175 624
#  262 707 429 234 677 429 548 774 394 418 476 441 707 309 430 682 573 133
#  140 431 772 373 112 595 517 627 758 597 662 469 590 606 556 625 607 784
#  535 618 464 364 337 179 794 194 185 467 719 435 528 315 380 780 191 627
#  797 103 625 759 297 322 588 504 287 329 482 602 386 359 268 735 238 558
#  580 189 295 239 679 153 252 200 432 446 519 315 394 717 644 508 211 206
#  238 106 636 491 178 715]
#fifth array
# [304 331 503 615 107 784 337 237 207 271 121 594 126 419 155 628 294 202
#  612 430 537 606 756 274 154 448 295 135 116 795 129 101 373 213 552 614
#  631 630 698 132 204 269 731 554 705 571 261 153 704 398 687 571 184 177
#  412 459 398 261 373 555 436 304 377 790 321 118 448 582 292 764 578 448
#  510 364 232 194 705 790 599 583 634 149 340 590 612 109 791 439 540 266
#  237 495 255 172 515 361 707 533 180 178 472 294 347 702 219 793 481 261
#  435 571 414 125 799 511]
#sixth array
# [795 621 544 664 135 204 140 201 456 410 645 213 422 235 637 300 217 556
#  601 282 268 499 646 394 573 207 673 543 114 115 175 200 611 354 313 106
#  142 478 229 287 721 456 719 189 304 120 494 621 634 538 756 302 654 789
#  217 418 591 533 313 274 140 562 458 331 451 231 302 300 213 159 704 616
#  655 112 105 394 326 236 528 216 661 184 462 548 279 759 288 522 640 450
#  448 483 377 411 531 686 186 599 354 524 125 520 650 611 388 321 254 303
#  677 499 475 716 678 672]
#seventh array
# [151 775 186 783 175 214 220 305 365 678 515 711 466 509 487 273 352 495
#  347 684 133 222 114 285 444 258 118 510 703 661 279 322 675 477 453 518
#  212 195 442 309 574 241 384 790 287 140 414 671 163 565 474 430 425 605
#  192 780 410 456 498 590 218 682 137 579 564 604 780 597 409 662 566 101
#  342 678 721 511 648 759 284 417 487 278 102 521 326 243 454 321 582 128
#  775 789 641 192 272 329 455 529 532 479 462 152 477 169 320 656 785 429
#  674 250 283 612 392 359]
#eigth array
# [328 527 663 368 519 481 716 237 513 102 602 500 158 426 414 383 616 138
#  102 332 535 146 244 181 295 144 204 287 300 308 116 458 174 274 213 487
#  774 563 278 438 761 731 531 574 769 436 569 112 239 489 601 686 453 142
#  136 232 412 615 726 719 680 231 640 644 126 374 596 164 517 234 120 420
#  217 486 634 275 303 618 451 140 271 330 139 410 227 428 168 453 452 206
#  338 768 681 105 234 159 171 509 226 252 402 303 122 495 352 404 674 761
#  517 464 341 295 172 700]
#ninth array
# [203 243 511 573 684 134 253 431 444 117 555 385 238 170 745 640 227 269
#  713 714 706 128 537 441 153 672 423 121 712 726 437 689 793 654 453 150
#  169 515 122 187 592 328 615 524 279 380 166 122 619 424 518 283 242 194
#  621 192 180 282 370 530 759 539 394 436 686 322 656 712 244 225 711 430
#  470 156 463 631 209 279 676 649 434 359 184 339 215 231 285 596 313 171
#  647 258 432 108 587 761 243 625 102 203 466 176 256 295 248 723 584 270
#  224 609 130 654 617 448]
#tenth array
# [363 632 338 234 722 337 443 533 646 155 463 326 136 165 197 789 438 481
#  520 467 326 515 784 164 470 563 598 340 726 430 721 760 616 176 700 561
#  317 186 386 572 587 302 545 178 182 539 325 109 387 370 438 553 253 683
#  642 761 486 421 111 592 320 249 477 223 251 314 303 277 290 428 455 558
#  487 101 798 274 646 426 532 474 138 277 673 251 151 561 316 128 725 554
#  345 146 288 708 761 755 788 177 132 720 512 274 260 631 201 537 650 328
#  531 719 544 451 548 120]








