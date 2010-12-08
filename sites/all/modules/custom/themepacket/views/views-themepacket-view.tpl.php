<?php 
// $Id$
/*DDDDDDDDDDDDDDDDDDDDDDDDDDkk      DDDDDDkk DDDDDDDDDDDDDDDDDDDD DDDDDDDDtt        kkDDDDDD kkDDDDDDDDDDDDDDDDDDkk                                  
MMMMMMMMMMMMMMMMMMMMMMMMMMMMDD      MMMMMMMM MMMMMMMMMMMMMMMMMMMM MMMMMMMMDD      ttMMMMMMMM MMMMMMMMMMMMMMMMMMMMDD                                  
MMMMMMMMMMMMMMMMMMMMMMMMMMMMDD      MMMMMMMM MMMMMMMMMMMMMMMMMMMM MMMMMMMMMMtt    DDMMMMMMMM DDMMMMMMMMMMMMMMMMMMDD                                  
DDMMDDMMMMMMMMMMDDDDMMMMMMMMkk      MMMMMMMM MMMMMMMMDDMMMMMMMMMM MMMMMMMMMMDD  ttMMMMMMMMMM MMMMMMMMMMDDMMMMMMMMDD                                  
      ttMMMMMMDD    kkMMMMMMMMDDDDDDMMMMMMMM MMMMMMDD             MMMMMMMMMMMM  MMMMMMMMMMMM MMMMMMMM                                                
      ttMMMMMMDD    ttMMMMMMMMMMMMMMMMMMMMMM MMMMMMMMMMMMMMDD     MMMMMMMMMMMMMMMMMMMMMMMMMM MMMMMMMMMMMMMMMMkk                                      
      ttMMMMMMDD    ttMMMMMMMMMMMMMMMMMMMMMM MMMMMMMMMMMMMMMM     MMMMMMMMMMMMMMMMMMMMMMMMMM MMMMMMMMMMMMMMMMkk                                      
      ttMMMMMMDD    ttMMMMMMMMMMMMMMMMMMMMMM MMMMMMDDtttttttt     MMMMMMMMMMMMMMMMMMMMMMMMMM MMMMMMMMtttttttt                                        
      ttMMMMMMDD    ttMMMMMMDD      MMMMMMMM MMMMMMDDtttttttttttt MMMMMMMMttMMMMMMDDkkMMMMMM MMMMMMMMtttttttttttttttt                                
      ttMMMMMMDD    ttMMMMMMDD      MMMMMMMM MMMMMMMMMMMMMMMMMMMM MMMMMMMM  DDMMMMttkkMMMMMM MMMMMMMMMMMMMMMMMMMMMMMM                                
      ttMMMMMMDD    ttMMMMMMDD      MMMMMMMM MMMMMMMMMMMMMMMMMMMM MMMMMMMM  ttMMDD  DDMMMMMM DDMMMMMMMMMMMMMMMMMMMMMM                                
      ttMMMMMMMM    kkMMMMMMDD      MMMMMMMM MMMMMMMMMMMMMMMMMMMM MMMMMMMM    MM    DDMMMMMM MMMMMMMMMMMMMMMMMMMMMMMM                                
                                                                                                                                                        
DDDDDDDDDDDDDDDDDDDDDDkktt          MMDDDDDDDDDD              ttkkDDDDDDDDDDDDDD MMDDMMkk    DDDDDDDD  ttMMDDDDDDDDDDDDDDDDDD DDDDDDDDDDDDDDDDDDDDDDtt
MMMMMMMMMMMMMMMMMMMMMMMMMMkk      kkMMMMMMMMMMMMtt          DDMMMMMMMMMMMMMMMMMM MMMMMMDD  kkMMMMMMkk  kkMMMMMMMMMMMMMMMMMMMM MMMMMMMMMMMMMMMMMMMMMMtt
MMMMMMMMMMMMMMMMMMMMMMMMMMMM      MMMMMMMMMMMMMMMM        MMMMMMMMMMMMMMMMMMMMMM MMMMMMkk  MMMMMMDD    kkMMMMMMMMMMMMMMMMMMMM MMMMMMMMMMMMMMMMMMMMMMtt
DDMMMMMMMMMMDD      kkMMMMMMkk    MMMMMMkkMMMMMMMM      MMMMMMMMMMMMMMMMMMMMMMMM MMMMMMkkMMMMMMMM      kkMMMMMMMMMMMMMMMMMMDD MMMMMMMMMMMMMMMMMMMMMMtt
    kkMMMMMMDD      ttMMMMMMkk  DDMMMMMM  ttMMMMMMkk  ttMMMMMMMMDD               MMMMMMMMMMMMMM        kkMMMMMMkk                   kkMMMMMMtt        
    DDMMMMMMMMDDDDDDMMMMMMMMtt  MMMMMMMM    MMMMMMMM  ttMMMMMMMM                 MMMMMMMMMMMMtt        kkMMMMMMMMDDDDMMDD           DDMMMMMMtt        
    DDMMMMMMMMMMMMMMMMMMMMMM  ttMMMMMMkk    DDMMMMMM  ttMMMMMMMM                 MMMMMMMMMMMMtt        kkMMMMMMMMMMMMMMMM           DDMMMMMMtt        
    DDMMMMMMMMMMMMMMMMMMDD    DDMMMMMMkkkkkkDDMMMMMMkk  MMMMMMMMtt               MMMMMMMMMMMMMM        kkMMMMMMkk                   DDMMMMMMtt        
    DDMMMMMMDD    tt          MMMMMMMMMMMMMMMMMMMMMMDD  MMMMMMMMMMDDkkkkkkkkkkkk MMMMMMDDMMMMMMDDkkkkkkDDMMMMMMDDkkkkkkkkkkkkkk     DDMMMMMMtt        
    DDMMMMMMDD              ttMMMMMMMMMMMMMMMMMMMMMMMMtt  MMMMMMMMMMMMMMMMMMMMMM MMMMMMkkttMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM     DDMMMMMMtt        
    DDMMMMMMDD              DDMMMMMMDD      ttMMMMMMMMkk    MMMMMMMMMMMMMMMMMMMM MMMMMMDD  kkMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM     DDMMMMMMtt        
    kkMMMMMMkk              MMMMMMMMkk        kkMMMMMMDD      kkDDMMMMMMMMMMMMMM MMMMMMkk    DDMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM     kkMMMM*/?>
<div<?php print $attributes; ?>>
  <?php if ($admin_links): ?>
    <div class="views-admin-links views-hide"><?php print $admin_links; ?></div>
  <?php endif; ?>
  <?php if ($header): ?>
    <div class="view-header"><?php print $header; ?></div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters"><?php print $exposed; ?></div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before"><?php print $attachment_before; ?></div>
  <?php endif; ?>

  <?php if ($rows): ?>
    <?php print $rows; ?>
  <?php elseif ($empty): ?>
    <div class="view-empty"><?php print $empty; ?></div>
  <?php endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after"><?php print $attachment_after; ?></div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer"><?php print $footer; ?></div>
  <?php endif; ?>

  <?php if ($feed_icon): ?>
    <div class="feed-icon"><?php print $feed_icon; ?></div>
  <?php endif; ?>
</div>